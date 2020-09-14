#pragma once
#include "GraphicsDevice/GraphicsDevice.h"
#include "IUnityRenderingExtensions.h"
#include "Size.h"
#include "common_video/include/video_frame_buffer.h"
#include "rtc_base/ref_counted_object.h"
#include <shared_mutex>

#if CUDA_PLATFORM
#include <cuda.h>
#endif

namespace unity
{
namespace webrtc
{
    using namespace ::webrtc;

    class GpuMemoryBufferHandle
    {
    public:
        GpuMemoryBufferHandle();
        GpuMemoryBufferHandle(GpuMemoryBufferHandle&& other);
        GpuMemoryBufferHandle& operator=(GpuMemoryBufferHandle&& other);
        ~GpuMemoryBufferHandle();

#if CUDA_PLATFORM
        CUarray array;
        CUdeviceptr devicePtr;
        CUgraphicsResource resource;
#endif
    };

    class ITexture2D;
    class GpuMemoryBufferInterface : public rtc::RefCountInterface
    {
    public:
        virtual Size GetSize() const = 0;
        virtual UnityRenderingExtTextureFormat GetFormat() const = 0;
        virtual rtc::scoped_refptr<I420BufferInterface> ToI420() = 0;

        virtual void CopyTo(ITexture2D* tex) = 0;
    protected:
        ~GpuMemoryBufferInterface() override = default;
    };

    class GpuMemoryBufferFromUnity : public rtc::RefCountedObject<GpuMemoryBufferInterface>
    {
    public:
        GpuMemoryBufferFromUnity(
            IGraphicsDevice* device, NativeTexPtr ptr, const Size& size, UnityRenderingExtTextureFormat format);
        GpuMemoryBufferFromUnity(const GpuMemoryBufferFromUnity&) = delete;
        GpuMemoryBufferFromUnity& operator=(const GpuMemoryBufferFromUnity&) = delete;
        ~GpuMemoryBufferFromUnity() override;

        void CopyBuffer(NativeTexPtr ptr);
        UnityRenderingExtTextureFormat GetFormat() const override;
        Size GetSize() const override;
        rtc::scoped_refptr<I420BufferInterface> ToI420() override;

        void CopyTo(ITexture2D* tex) override;
    private:
        IGraphicsDevice* device_;
        UnityRenderingExtTextureFormat format_;
        Size size_;
        std::unique_ptr<ITexture2D> texture_;
    };

    //class FakeGpuMemoryBuffer : public rtc::RefCountedObject<GpuMemoryBufferInterface>
    //{
    //public:
    //    FakeGpuMemoryBuffer(const ITexture2D* texture, UnityRenderingExtTextureFormat format);
    //    FakeGpuMemoryBuffer(const FakeGpuMemoryBuffer&) = delete;
    //    FakeGpuMemoryBuffer& operator=(const FakeGpuMemoryBuffer&) = delete;
    //    ~FakeGpuMemoryBuffer() override;

    //    Size GetSize() const override { return size_; }
    //    UnityRenderingExtTextureFormat GetFormat() const override { return format_; }
    //    rtc::scoped_refptr<I420BufferInterface> ToI420() override { return nullptr; }

    //    void CopyTo(ITexture2D* tex) override;
    //private:
    //    Size size_;
    //    UnityRenderingExtTextureFormat format_;
    //    std::unique_ptr<const ITexture2D> texture_;
    //};

}
}
