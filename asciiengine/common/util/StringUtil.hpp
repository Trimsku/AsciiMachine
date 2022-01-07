#pragma once
#include "../../astd/String.hpp"

namespace ascii { namespace util {
        astd::string getFileResources(const char* path_to_file) noexcept;
}} // namespace ascii::util