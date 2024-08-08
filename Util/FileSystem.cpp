// No include of FileSystem.h, just include the impl file to define the function implementations
#ifndef ARMIPS_USE_STD_FILESYSTEM
#include <ghc/fs_impl.hpp>

#ifdef WASI
#include "FileSystem.h"

namespace fs
{
  bool exists(const path &p)
  {
    std::error_code errorCode;
    return ghc::filesystem::exists(p, errorCode);
  }

  path absolute(const path &p)
  {
    std::error_code errorCode;
    return ghc::filesystem::absolute(p, errorCode);
  }

  path current_path()
  {
    std::error_code errorCode;
    return ghc::filesystem::current_path(errorCode);
  }

  void current_path(const path &p)
  {
    std::error_code errorCode;
    return ghc::filesystem::current_path(p, errorCode);
  }

  void current_path(const path &p, std::error_code &errorCode)
  {
    return ghc::filesystem::current_path(p, errorCode);
  }

  uintmax_t file_size(const path &p)
  {
    std::error_code errorCode;
    return ghc::filesystem::file_size(p, errorCode);
  }

  uintmax_t file_size(const path &p, std::error_code &errorCode)
  {
    return ghc::filesystem::file_size(p, errorCode);
  }
}
#endif

#endif
