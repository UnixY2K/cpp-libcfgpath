cpp_libcfgpath_incl = include_directories('include')

cpp_libcfgpath_srcs = [
    'src/cfgpath.cpp',
]
cpp_libcfgpath_args = []
cpp_libcfgpath_link = []
cpp_libcfgpath_deps = [
    xxhash_dep
]

subdir('impl')

# add implementation
cpp_libcfgpath_srcs += cpp_libcfgpath_impl_srcs
cpp_libcfgpath_args += cpp_libcfgpath_impl_args
cpp_libcfgpath_link += cpp_libcfgpath_impl_link
cpp_libcfgpath_deps += cpp_libcfgpath_impl_deps

cpp_libcfgpath_lib = library('cfgpathpp',
                        cpp_libcfgpath_srcs,
                        include_directories : [
                            cpp_libcfgpath_incl,
                            cpp_libcfgpath_impl_incl],
                        cpp_args: cpp_libcfgpath_args,
                        dependencies : cpp_libcfgpath_deps)

cpp_libcfgpath_dep = declare_dependency(
    link_with: cpp_libcfgpath_lib,
    include_directories: cpp_libcfgpath_incl,
)
