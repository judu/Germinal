# This file is part of Germinal.
#
# Copyright 2011 Marc-Antoine Perennou <Marc-Antoine@Perennou.com>
#
# Germinal is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# Germinal is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with Germinal.  If not, see <http://www.gnu.org/licenses/>.

ACLOCAL_AMFLAGS  = -I m4
SUBDIRS = po

# Directories

applicationsdir = $(datadir)/applications

# Data stuff

gsettings_SCHEMAS = data/org.gnome.Germinal.gschema.xml

applications_in_files = data/germinal.desktop.in
applications_DATA = $(applications_in_files:.desktop.in=.desktop)

# Binaries

bin_PROGRAMS = germinal

# Sources

germinal_SOURCES = \
	src/germinal.c

# CFLAGS

AM_CFLAGS = \
	-Wall -Wextra -pedantic \
	-O2 -march=native \
	-DLOCALEDIR=\"${localedir}\" \
	$(GLIB_CFLAGS) \
	$(GIO_CFLAGS) \
	$(GTK_CFLAGS) \
	$(GDK_CFLAGS) \
	$(VTE_CFLAGS)

# LDADD

AM_LDFLAGS = \
	-Wl,--as-needed \
	-Wl,-O2

AM_LIBS = \
	$(GLIB_LIBS) \
	$(GIO_LIBS) \
	$(GTK_LIBS) \
	$(GDK_LIBS) \
	$(VTE_LIBS)

germinal_LDADD = \
	$(AM_LIBS)

# Distribution stuff

EXTRA_DIST = \
	$(applications_in_files) \
	data/org.gnome.Germinal.gschema.xml.in.in \
	autogen.sh

CLEANFILES = \
	${germinal_SOURCES:.c=.o} \
	$(applications_DATA) \
	$(gsettings_SCHEMAS) \
	gschemas.compiled

# Special rules

@INTLTOOL_DESKTOP_RULE@
@INTLTOOL_XML_NOMERGE_RULE@
@GSETTINGS_RULES@

update-po:
	$(MAKE) -C po $@

gschemas.compiled: $(gsettings_SCHEMAS:.xml=.valid)
	$(AM_V_GEN) $(GLIB_COMPILE_SCHEMAS) --targetdir=. .

release:
	git commit -asm "Release $(PACKAGE_NAME) $(PACKAGE_VERSION)"
	git tag -sm "Release $(PACKAGE_NAME) $(PACKAGE_VERSION)" v$(PACKAGE_VERSION)
	$(MAKE) distcheck

# Generate a ChangeLog file from 'git log'
dist-hook:
	@if test -d "$(srcdir)/.git"; \
        then \
                echo Creating ChangeLog && \
                ( cd "$(top_srcdir)" && \
                  echo '# Generated by Makefile. Do not edit.'; echo; \
                  $(top_srcdir)/.aux/missing --run git log --stat \
                ) > ChangeLog.tmp \
                && mv -f ChangeLog.tmp $(top_distdir)/ChangeLog \
                || ( rm -f ChangeLog.tmp ; \
                     echo Failed to generate ChangeLog >&2 ); \
        else \
                echo A git clone is required to generate a ChangeLog >&2; \
        fi
