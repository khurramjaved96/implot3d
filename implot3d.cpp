//--------------------------------------------------
// ImPlot3D
// implot3d.cpp
// Date: 2024-11-16
// By Breno Cunha Queiroz
//--------------------------------------------------

// Table of Contents:
// [SECTION] Includes
// [SECTION] Context

//-----------------------------------------------------------------------------
// [SECTION] Includes
//-----------------------------------------------------------------------------

#include "implot3d.h"
#include "implot3d_internal.h"

#ifndef IMGUI_DISABLE

//-----------------------------------------------------------------------------
// [SECTION] Context
//-----------------------------------------------------------------------------

// Global plot context
#ifndef GImPlot
ImPlot3DContext* GImPlot3D = nullptr;
#endif

ImPlot3DContext* CreateContext() {
    ImPlot3DContext* ctx = IM_NEW(ImPlot3DContext)();
    if (GImPlot3D == nullptr)
        SetCurrentContext(ctx);
    return ctx;
}

void DestroyContext(ImPlot3DContext* ctx) {
    if (ctx == nullptr)
        ctx = GImPlot3D;
    if (GImPlot3D == ctx)
        SetCurrentContext(nullptr);
    IM_DELETE(ctx);
}

ImPlot3DContext* GetCurrentContext() { return GImPlot3D; }

void SetCurrentContext(ImPlot3DContext* ctx) { GImPlot3D = ctx; }

#endif // #ifndef IMGUI_DISABLE
