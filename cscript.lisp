(k:library "netcdf-cxx4" :required t)

(k:systems :netcdf)

(k:sources :iclasp #~"src/netcdf.cc")

; (k:sources :install-code
;            #~"src/lisp/netcdf.asd"
;            #~"src/lisp/packages.lisp"
;            #~"src/lisp/interface.lisp")
