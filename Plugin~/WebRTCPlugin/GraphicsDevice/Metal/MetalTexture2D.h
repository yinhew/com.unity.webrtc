#pragma once

#include "GraphicsDevice/ITexture2D.h"
#include "WebRTCMacros.h"

namespace unity
{
namespace webrtc
{

    class MTLTexture;
    struct MetalTexture2D : ITexture2D {
    public:
        id<MTLTexture> m_texture;

        MetalTexture2D(uint32_t w, uint32_t h, id<MTLTexture> tex);
        virtual ~MetalTexture2D();
        
        std::unique_ptr<GpuMemoryBufferHandle> Map() override
        {
            // todo(kazuki):: not supported
            throw;
        }

        inline void* GetNativeTexturePtrV() override;
        inline const void* GetNativeTexturePtrV() const override;
        inline void* GetEncodeTexturePtrV() override;
        inline const void* GetEncodeTexturePtrV() const override;

    };

//---------------------------------------------------------------------------------------------------------------------

    void* MetalTexture2D::GetNativeTexturePtrV() { return m_texture; }
    const void* MetalTexture2D::GetNativeTexturePtrV() const { return m_texture; };
    void* MetalTexture2D::GetEncodeTexturePtrV() { return m_texture; }
    const void* MetalTexture2D::GetEncodeTexturePtrV() const { return m_texture; }

} // end namespace webrtc
} // end namespace unity
