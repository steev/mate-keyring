
asn1-def-test.c: test.asn
	$(ASN1PARSER) -o asn1-def-test.c $(srcdir)/test.asn

INCLUDES = \
	-I$(top_srcdir)/egg \
	-DSRCDIR=$(srcdir) \
	$(GLIB_CFLAGS)

LDADD =  \
	$(top_builddir)/egg/libegg.la \
	$(LIBGCRYPT_LIBS) \
	$(GTHREAD_LIBS) \
	$(GLIB_LIBS)

TEST_PROGS = \
	test-asn1 \
	test-dn \
	test-cleanup \
	test-hex \
	test-oid \
	test-secmem \
	test-padding \
	test-symkey \
	test-openssl \
	test-dh \
	test-spawn

test_asn1_SOURCES = \
	test-asn1.c \
	asn1-def-test.c

check_PROGRAMS = $(TEST_PROGS)

test: $(TEST_PROGS)
	SRCDIR='$(srcdir)' gtester -k --verbose ${TEST_PROGS}

check-local: test

if WITH_TESTS
all-local: $(check_PROGRAMS)
endif

EXTRA_DIST = \
	test.asn \
	files

# ------------------------------------------------------------------------------

noinst_PROGRAMS = \
	test-asn1x

test_asn1x_SOURCES = \
	test-asn1x.c

test_asn1x_LDADD = \
	$(top_builddir)/egg/libegg-asn1x.la \
	$(LIBTASN1_LIBS) \
	$(LDADD)
