#!/bin/bash -eu

if [ ! -e "$(pwd)/depot_tools" ]
then
  git clone --depth 1 https://chromium.googlesource.com/chromium/tools/depot_tools.git
fi

export COMMAND_DIR=$(cd $(dirname $0); pwd)
export PATH="$(pwd)/depot_tools:$PATH"
export WEBRTC_VERSION=4515
export OUTPUT_DIR="$(pwd)/out"
export ARTIFACTS_DIR="$(pwd)/artifacts"

if [ ! -e "$(pwd)/src" ]
then
  fetch --nohooks webrtc
  cd src
  sudo sh -c 'echo 127.0.1.1 $(hostname) >> /etc/hosts'
  sudo git config --system core.longpaths true
  git checkout "refs/remotes/branch-heads/$WEBRTC_VERSION"
  cd ..
  gclient sync -f
fi

# add jsoncpp
patch -N "src/BUILD.gn" < "$COMMAND_DIR/patches/add_jsoncpp.patch"

# add objc library to use videotoolbox
patch -N "src/sdk/BUILD.gn" < "$COMMAND_DIR/patches/add_objc_deps.patch"

# avoid crashes when using Full HD resolution with HWA enabled
# workaround referred from this discussion: https://groups.google.com/g/discuss-webrtc/c/AVeyMXnM0gY
patch -N "src/sdk/objc/components/video_codec/RTCVideoEncoderH264.mm" < "$COMMAND_DIR/patches/avoid_crashusingvideoencoderh264.patch"

mkdir -p "$ARTIFACTS_DIR/lib"

for is_debug in "true" "false"
do
  for target_cpu in "x64" "arm64"
  do

    # generate ninja files
    gn gen "$OUTPUT_DIR" --root="src" \
      --args="is_debug=${is_debug} \
      target_os=\"mac\"  \
      target_cpu=\"${target_cpu}\" \
      rtc_include_tests=false \
      rtc_build_examples=false \
      rtc_use_h264=false \
      symbol_level=0 \
      enable_iterator_debugging=false \
      is_component_build=false \
      use_rtti=true \
      rtc_use_x11=false \
      libcxx_abi_unstable=false"

    # build static library
    ninja -C "$OUTPUT_DIR" webrtc

    # copy static library
    mkdir -p "$ARTIFACTS_DIR/lib/${target_cpu}"
    cp "$OUTPUT_DIR/obj/libwebrtc.a" "$ARTIFACTS_DIR/lib/${target_cpu}/"
  done

  filename="libwebrtc.a"
  if [ $is_debug = "true" ]; then
    filename="libwebrtcd.a"
  fi

  # make universal binary
  lipo -create -output \
  "$ARTIFACTS_DIR/lib/${filename}" \
  "$ARTIFACTS_DIR/lib/arm64/libwebrtc.a" \
  "$ARTIFACTS_DIR/lib/x64/libwebrtc.a"

  rm -r "$ARTIFACTS_DIR/lib/arm64"
  rm -r "$ARTIFACTS_DIR/lib/x64"
done

# fix error when generate license
patch -N "./src/tools_webrtc/libs/generate_licenses.py" < \
  "$COMMAND_DIR/patches/generate_licenses.patch"

vpython "./src/tools_webrtc/libs/generate_licenses.py" \
  --target //:default "$OUTPUT_DIR" "$OUTPUT_DIR"

cd src
find . -name "*.h" -print | cpio -pd "$ARTIFACTS_DIR/include"

cp "$OUTPUT_DIR/LICENSE.md" "$ARTIFACTS_DIR"

# create zip
cd "$ARTIFACTS_DIR"
zip -r webrtc-mac.zip lib include LICENSE.md
