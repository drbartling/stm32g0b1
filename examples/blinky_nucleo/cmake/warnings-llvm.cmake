function(set_warnings target_name)
    set(C_WARNINGS
        -fdiagnostics-show-option
        -Wall
        -Wextra # reasonable and standard
        -Wshadow # warn the user if a variable declaration shadows one from a
                 # parent context
        -Wcast-align # warn for potential performance problem casts
        -Wunused # warn on anything being unused
        -Wconversion # warn on type conversions that may lose data
        -Wsign-conversion # warn on sign conversions
        -Wnull-dereference # warn if a null dereference is detected
        -Wdouble-promotion # warn if float is implicit promoted to double
        -Wformat=2 # warn on security issues around functions that format output
                   # (ie printf)
        -Wimplicit-fallthrough # warn on statements that fallthrough without an
                               # explicit annotation
    )
    set(CXX_WARNINGS
        -Wnon-virtual-dtor # warn the user if a class with virtual functions has
                           # a non-virtual destructor. This helps catch hard to
                           # track down memory errors
        -Wold-style-cast # warn for c-style casts
        -Woverloaded-virtual # warn if you overload (not override) a virtual
                             # function
    )

    target_compile_options(
        ${target_name} INTERFACE $<$<COMPILE_LANGUAGE:CXX>:${CXX_WARNINGS}>
                                 $<$<COMPILE_LANGUAGE:C>:${C_WARNINGS}>
    )
endfunction()
