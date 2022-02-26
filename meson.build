project(
    'cpp libcfgpath', 'cpp',
    default_options: ['cpp_std=c++17'],
    version: '1.0.0 v2021',
    license: 'BSD-3'
)
version = '1.0.0 v2022'

catch2_dep = dependency(
                'catch2',
                fallback: ['catch2', 'catch2_dep']
)

## xxhash - for fast hash 
xxhash_dep = dependency(
                'xxhash',
                fallback: ['xxhash', 'xxhash_dep']
)

subdir('libcfgpath')
if get_option('build_tests')
    subdir('test')
else
    message('Skipping tests')
endif
