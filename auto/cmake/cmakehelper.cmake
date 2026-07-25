function(setup_precompiled_headers TARGET PCH_SOURCE PCH_HEADER SOURCE_FILES)
    if(MSVC)
        get_filename_component(PCH_HEADER_NAME ${PCH_HEADER} NAME)
        target_sources(${TARGET} PRIVATE ${PCH_HEADER} ${PCH_SOURCE})
        set_source_files_properties(${PCH_SOURCE} PROPERTIES COMPILE_FLAGS "/Yc${PCH_HEADER_NAME}")
        
        foreach(SOURCE_FILE ${SOURCE_FILES})
            if(${SOURCE_FILE} MATCHES "\\.cpp$" AND NOT ${SOURCE_FILE} STREQUAL ${PCH_SOURCE})
                set_source_files_properties(${SOURCE_FILE} PROPERTIES COMPILE_FLAGS "/Yu${PCH_HEADER_NAME}")
  
            endif()
        endforeach()

        target_compile_options(${TARGET} PRIVATE "/FI${PCH_HEADER_NAME}")
    endif()
endfunction()