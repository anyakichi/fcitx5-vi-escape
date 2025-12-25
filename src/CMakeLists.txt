add_library(vi_escape SHARED vi_escape.cpp)
target_link_libraries(vi_escape PRIVATE Fcitx5::Core)
target_compile_features(vi_escape PRIVATE cxx_std_20)

install(TARGETS vi_escape
        LIBRARY DESTINATION ${FCITX_INSTALL_LIBDIR}/fcitx5)
