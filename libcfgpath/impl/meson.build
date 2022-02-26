fs = import('fs')

cpp_libcfgpath_impl_incl = [include_directories('include')]
cpp_libcfgpath_impl_srcs = []
cpp_libcfgpath_impl_args = []
cpp_libcfgpath_impl_link = []
cpp_libcfgpath_impl_deps = []

impl_dir = host_machine.system()

cpp_libcfgpath_impl_src_dir = 'impl' / impl_dir

if fs.is_dir(impl_dir)
    message('Using ' + impl_dir + ' implementation: ')
    subdir(impl_dir)
    foreach src : impl_sources
        cpp_libcfgpath_impl_srcs += cpp_libcfgpath_impl_src_dir + '/' + src
    endforeach
else
    message('platform' + impl_dir + 'not supported, aborting')
    assert(false)
endif
