#pragma once

#include <c10/core/Device.h>
#include <c10/xpu/XPUDeviceProp.h>
#include <c10/xpu/XPUMacros.h>

// The naming convention used here matches the naming convention of torch.xpu

namespace c10::xpu {

// Log a warning only once if no devices are detected.
C10_XPU_API DeviceIndex device_count();

// Throws an error if no devices are detected.
C10_XPU_API DeviceIndex device_count_ensure_non_zero();

// If this function fails, return -1. Otherwise, return the number of Intel GPUs
// without the limitation of SYCL runtime in multi-processing.
C10_XPU_API DeviceIndex prefetch_device_count();

C10_XPU_API DeviceIndex current_device();

C10_XPU_API void set_device(DeviceIndex device);

C10_XPU_API int exchange_device(int device);

C10_XPU_API int maybe_exchange_device(int to_device);

C10_XPU_API sycl::device& get_raw_device(int device);

C10_XPU_API sycl::context& get_device_context();

C10_XPU_API void get_device_properties(DeviceProp* device_prop, int device);

C10_XPU_API int get_device_from_pointer(void* ptr);

} // namespace c10::xpu
