#include <string>
#include "spdlog/spdlog.h"

#include "libcamera-streamer/libcamera_streamer.hpp"
#include "libcamera-streamer/streamer_configuration.hpp"

auto main() -> int
{
    //spdlog::set_level(spdlog::level::trace);

    StreamerConfiguration configuration;
    configuration.Camera.width = 1280;
    configuration.Camera.height = 720;
    configuration.Camera.framerate = 60;
    configuration.Camera.denoise = "off";
    configuration.Output.Ip = "192.168.88.115";
    configuration.Output.Port = 5600;
    configuration.Encoder.framerate = 60;
    configuration.Encoder.bitrate = 5000000;
    configuration.Encoder.width = 1280;
    configuration.Encoder.height = 720;

    const auto streamer = std::make_unique<LibcameraStreamer>(configuration);
    streamer->Start();

    while (true)
    {
    }
    return 0;
}
