#!/bin/sh
# set -ex

# Check what MKL lib we have in MKLROOT
if [ -z "$MKLROOT" -o -z `find $MKLROOT -name libmkl_rt.so -print -quit` ]; then
  # mkl_rt has not been found; we are dealing with MKLML
  if [ -z "$LOCALMKL" ] ; then
    # LOCALMKL is not set, when MKLROOT was set manually and it points to MKLML in correct version
    LOCALMKL=`find $1 -name libmklml_intel.so`   # name of MKL lib
  fi

  if [ -n "$LOCALMKL" ] ; then
    LIBRARIES=`basename $LOCALMKL | sed -e 's/^.*lib//' | sed -e 's/\.so.*$//'`
    MKLROOT="$LOCALMKL"
  fi
else
  LIBRARIES="mkl_rt"
fi

echo $MKLROOT $LIBRARIES
