/*
 * Copyright (c) 2020-2021 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "gfx_utils/mem_api.h"
namespace OHOS {
#ifndef IMG_CACHE_MEMORY_CUSTOM
void* ImageCacheMalloc(ImageInfo& info)
{
    return malloc(info.dataSize);
}

void ImageCacheFree(ImageInfo& info)
{
    uint8_t* buf = const_cast<uint8_t*>(info.data);
    free(buf);
    info.data = nullptr;
    return;
}
#endif

#if !ENABLE_MEMORY_HOOKS
void* UIMalloc(uint32_t size)
{
    return malloc(size);
}

void UIFree(void* buffer)
{
    free(buffer);
}

void* UIRealloc(void* buffer, uint32_t size)
{
    return realloc(buffer, size);
}
#endif
} // namespace OHOS
