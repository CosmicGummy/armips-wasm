#pragma once

#ifdef ARMIPS_USE_STD_FILESYSTEM

#include <filesystem>
#include <fstream>

namespace fs
{
	using namespace std::filesystem;
	using ifstream = std::ifstream;
	using ofstream = std::ofstream;
	using fstream = std::fstream;
}

#else

#include <ghc/fs_fwd.hpp>

namespace fs
{
	using namespace ghc::filesystem;
	using ifstream = ghc::filesystem::ifstream;
	using ofstream = ghc::filesystem::ofstream;
	using fstream = ghc::filesystem::fstream;

	#ifdef WASI
		bool exists(const path &p);
		path absolute(const path &p);
		path current_path();
		void current_path(const path &p);
		void current_path(const path &p, std::error_code &errorCode);
		uintmax_t file_size(const path &p);
		uintmax_t file_size(const path &p, std::error_code &errorCode);
	#endif
}

#endif
