include(FetchContent)

# Download Catch2 as a ZIP file
FetchContent_Declare(
  Catch2
  URL          https://github.com/catchorg/Catch2/archive/refs/tags/v3.11.0.zip
  URL_HASH     SHA256=faa38e0b3899151d5c1b1d81f15ba7b6d25c6c27d060094212392e8f6bc1dce3
  DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)

FetchContent_MakeAvailable(Catch2)