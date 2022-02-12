cpp_libcfgpath_inc = include_directories('include')

cpp_libcfgpath_srcs = [
    'src/cfgpath.cpp',
]
cpp_libcfgpath_args = []
cpp_libcfgpath_link = []
cpp_libcfgpath_deps = []

subdir('impl')

# add implementation
cpp_libcfgpath_srcs += cpp_libcfgpath_impl_sources
cpp_libcfgpath_args    += cpp_libcfgpath_impl_args
cpp_libcfgpath_link    += cpp_libcfgpath_impl_link
cpp_libcfgpath_deps    += cpp_libcfgpath_impl_deps

cpp_libcfgpath_lib = library('appcenter-sdk',
                        cpp_libcfgpath_srcs,
                        include_directories : cpp_libcfgpath_inc,
                        cpp_args: cpp_libcfgpath_args,
                        dependencies : cpp_libcfgpath_deps)

cpp_libcfgpath_dep = declare_dependency(
    link_with: cpp_libcfgpath_lib,
    include_directories: cpp_libcfgpath_inc,
)
