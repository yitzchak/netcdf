#include <clasp/clasp.h>
#include <clasp/core/translators.h>
#include <ncDim.h>
#include <ncVar.h>
#include <ncFile.h>

PACKAGE_USE("COMMON-LISP");
PACKAGE_SHADOW("CLOSE")
PACKAGE_SHADOW("OPEN")
NAMESPACE_PACKAGE_ASSOCIATION(netcdf_lib, netcdf_pkg, "NETCDF");

template <> struct translate::from_object<netCDF::NcFile::FileMode> {
  netCDF::NcFile::FileMode _v;
  from_object(core::T_sp o) {
    if (o == INTERN_(kw, read)) {
      _v = netCDF::NcFile::FileMode::read;
    } else if (o == INTERN_(kw, write)) {
      _v = netCDF::NcFile::FileMode::write;
    } else if (o == INTERN_(kw, replace)) {
      _v = netCDF::NcFile::FileMode::replace;
    } else if (o == INTERN_(kw, new)) {
      _v = netCDF::NcFile::FileMode::newFile;
    } else {
      SIMPLE_ERROR_SPRINTF("Could not convert %s to netCDF::NcFile::FileMode", core::_rep_(o).c_str());
    }
  }
};

template <> struct translate::from_object<netCDF::NcGroup::Location> {
  netCDF::NcFile::FileMode _v;
  from_object(core::T_sp o) {
    if (o == INTERN_(kw, current)) {
      _v = netCDF::NcGroup::Location::Current;
    } else if (o == INTERN_(kw, children)) {
      _v = netCDF::NcGroup::Location::Children;
    } else if (o == INTERN_(kw, parents_and_current)) {
      _v = netCDF::NcGroup::Location::ParentsAndCurrent;
    } else if (o == INTERN_(kw, children_and_current)) {
      _v = netCDF::NcGroup::Location::ChildrenAndCurrent;
    } else if (o == INTERN_(kw, all)) {
      _v = netCDF::NcGroup::Location::All;
    } else {
      SIMPLE_ERROR_SPRINTF("Could not convert %s to netCDF::NcGroup::Location", core::_rep_(o).c_str());
    }
  }
};

namespace netcdf_lib {

CL_EXPOSE void netcdf_startup() {
  clbind::package_ pkg(netcdf_pkg);

  clbind::class_<netCDF::NcDim>(pkg, "dimension")
      .def("dimension-size", &netCDF::NcDim::getSize)
      .def("dimension-name", &netCDF::NcDim::getName)
      .def("dimension-unlimitedp", &netCDF::NcDim::isUnlimited);

  clbind::class_<netCDF::NcFile>(pkg, "file")
      .def_constructor("open", clbind::constructor<const std::string &, netCDF::NcFile::FileMode>())
      .def("close", &netCDF::NcFile::close);

  clbind::class_<netCDF::NcFile>(pkg, "group")
      .def("get-dimension", &netCDF::NcFile::getDim);
}

} // namespace netcdf_lib
