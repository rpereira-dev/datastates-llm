#include "core_impl.hpp"


namespace datastates {

core_impl_t::core_impl_t(size_t host_cache_size, int gpu_id_, int rank_, bool use_io_uring_, size_t fs_block_alignment_): 
    gpu_id(gpu_id_), rank(rank_), use_io_uring(use_io_uring_), fs_block_alignment(fs_block_alignment_) {
    LOGGER_DEBUG("DataStates initing: GPU: %d, host cache (MB): %zu",
           gpu_id_, host_cache_size*1024*1024);

    /* xkrt init */
    runtime.init();

    /* retrieve the driver */
    driver_t * driver = runtime.driver_get(XKRT_DRIVER_TYPE_CUDA);
    assert(driver);

    /* retrieve the device */
    device_driver_id_t device_driver_id = (device_driver_id_t) gpu_id_;
    device_t * device = driver_device_get(driver, gpu_id_);
    assert(device);
}

void core_impl_t::ckpt(std::uint64_t version, std::uint64_t uid, const char* ptr, const std::uint64_t size, const std::uint64_t file_offset, std::string path) {
    LOGGER_FATAL("Impl me");
}

void core_impl_t::ckpt_region(std::shared_ptr<mem_region_t> m) {
    LOGGER_FATAL("Impl me");
}

void core_impl_t::restore(std::uint64_t version, std::uint64_t uid, const char* ptr, const std::uint64_t size, const std::uint64_t file_offset, std::string path) {
    LOGGER_FATAL("Impl me");
}

void core_impl_t::wait(bool persist) {
    LOGGER_FATAL("Impl me");
}

std::string core_impl_t::get_queue_stats(bool for_flush_queue) {
    LOGGER_FATAL("Impl me");
}

std::string core_impl_t::shutdown() {
    wait(true);
    runtime.deinit();
    perf_profiler_t& perf_profiler = perf_profiler_t::get_instance();
    return perf_profiler.report();
}

core_impl_t::~core_impl_t() {
    shutdown();
}

} // namespace datastates
