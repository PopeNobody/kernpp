all:

include etc/sub-dir.mk

#$(warning libs: $(all/lib))
all: $(all/lib)

#$(warning exes: $(all/exe))
all: $(all/exe)




