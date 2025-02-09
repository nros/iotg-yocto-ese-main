SUMMARY = "Fast open source processor emulator"
DESCRIPTION = "QEMU is a hosted virtual machine monitor: it emulates the \
machine's processor through dynamic binary translation and provides a set \
of different hardware and device models for the machine, enabling it to run \
a variety of guest operating systems"
HOMEPAGE = "http://qemu.org"
LICENSE = "GPL-2.0-only & LGPL-2.1-only"

RDEPENDS:${PN}-ptest = "bash"

require qemu-targets.inc
inherit pkgconfig ptest

LIC_FILES_CHKSUM = "file://COPYING;md5=441c28d2cf86e15a37fa47e15a72fbac \
                    file://COPYING.LIB;endline=24;md5=8c5efda6cf1e1b03dcfd0e6c0d271c7f"

SRC_URI = "https://download.qemu.org/${BPN}-${PV}.tar.xz \
           file://powerpc_rom.bin \
           file://run-ptest \
           file://0001-qemu-Add-addition-environment-space-to-boot-loader-q.patch \
           file://0002-chardev-connect-socket-to-a-spawned-command.patch \
           file://0003-apic-fixup-fallthrough-to-PIC.patch \
           file://0004-configure-Add-pkg-config-handling-for-libgcrypt.patch \
           file://0005-qemu-Do-not-include-file-if-not-exists.patch \
           file://0006-qemu-Add-some-user-space-mmap-tweaks-to-address-musl.patch \
           file://0007-qemu-Determinism-fixes.patch \
           file://0008-tests-meson.build-use-relative-path-to-refer-to-file.patch \
           file://0009-Define-MAP_SYNC-and-MAP_SHARED_VALIDATE-on-needed-li.patch \
           file://0001-virtio-gpu-call-dpy_gl_frame_counter-at-every-guest-.patch \
           file://0002-ui-gtk-set-the-size-of-detached-window-to-default.patch \
           file://0003-ui-gtk-egl-make-sure-to-unbind-the-egl-context-from-.patch \
           file://0004-ui-gtk-adds-status-bar-for-expressing-ups-and-fps.patch \
           file://0005-ui-gtk-calling-gd_gl_frame_counter-at-every-draw-swa.patch \
           file://0006-ui-gtk-skip-drawing-guest-scanout-when-associated-VC.patch \
           file://0007-ui-gtk-set-the-ui-size-to-0-when-invisible.patch \
           file://0008-ui-gtk-reset-visible-flag-when-window-is-minimized.patch \
           file://0009-ui-gtk-Handle-relative-mode-events-correctly-with-Wa.patch \
           file://0010-ui-gtk-Disable-the-scanout-when-a-detached-tab-is-cl.patch \
           file://0011-ui-gtk-Factor-out-tab-window-creation-into-a-separat.patch \
           file://0012-ui-gtk-Add-a-new-parameter-to-assign-connectors-moni.patch \
           file://0013-ui-egl-helpers-display-EGL-error-if-eglCreateImageKH.patch \
           file://0014-ui-gtk-skip-drawing-if-any-of-ctx-surface-image-don-.patch \
           file://0015-ui-gtk-egl-should-assume-dmabuf-is-unusable-once-ren.patch \
           file://0016-ui-gtk-skip-refresh-rendering-if-VC-is-invisible.patch \
           file://0017-ui-gtk-unblock-gl-if-draw-submitted-already-or-fence.patch \
           file://0018-ui-gtk-remove-hp-timer-since-it-could-cause-invalid-.patch \
           file://0019-ui-gtk-make-sure-window-is-in-shown-state.patch \
           file://0020-ui-gtk-configure-the-area-of-the-texture-correctly.patch \
           file://0021-ui-gtk-making-dmabuf-NULL-when-dmabuf-is-not-valid-a.patch \
           file://0022-virtio-gpu-Provide-position-info-x-y-to-the-Guest.patch \
           file://0023-ui-gtk-Include-the-position-info-while-setting-the-u.patch \
           file://0024-ui-gtk-Add-support-for-extended-absolute-mode-for-th.patch \
           file://0025-i386-do-kvm_put_msr_feature_control-first-thing-when.patch \
           file://0026-i386-reset-KVM-nested-state-upon-CPU-reset.patch \
           file://0027-usb-hid-added-new-type-for-touch-stylus.patch \
           file://0028-ui-console-call-dpy_gl_count_frame-only-if-it-exists.patch \
           file://0029-virtio-gpu-udmabuf-create-udmabuf-for-blob-when-iov_.patch \
           file://0030-ui-gtk-handling-placement-of-QEMU-windows-when-monit.patch \
           file://0031-hw-virtio-Adds-support-for-VIRTIO_GPU_FORMAT_R8G8B8A.patch \
           file://0032-ui-gtk-WA-for-Yocto-IceWM.patch \
           file://0033-ui-gtk-fix-windows-state-event-call.patch \
           file://0034-ui-gtk-set-the-default-size-of-new-window-to-vc-gfx..patch \
           file://0035-ui-gtk-vc-page-number-correction.patch \
           file://0036-ui-gtk-disable-state-change-temporarily.patch \
           file://0037-virtio-gpu-VIRTIO_GPU_RESP_ERR_OUT_OF_MEMORY-if-udma.patch \
           file://0038-ui-console-display-inactive-display-output-when-repl.patch \
           file://0039-ui-gtk-egl-prevent-race-condition-if-refresh-is-call.patch \
           file://0040-virtio-gpu-replace-the-surface-with-null-surface-onl.patch \
           file://0041-ui-gtk-egl-Make-sure-the-right-EGL-context-is-curren.patch \
           file://0042-ui-gtk-use-handler-disconnect-then-reconnect.patch \
           file://0043-ui-gtk-additional-unblocking-condition-in-window-ico.patch \
           file://0044-ui-gtk-recover-window-in-all-events-other-than-minim.patch \
           file://0045-ui-gtk-gd_hw_gl_flushed-in-case-fence-is-already-ins.patch \
           "
BAR = "           file://0010-hw-pvrdma-Protect-against-buggy-or-malicious-guest-d.patch "
UPSTREAM_CHECK_REGEX = "qemu-(?P<pver>\d+(\.\d+)+)\.tar"

SRC_URI[sha256sum] = "a0634e536bded57cf38ec8a751adb124b89c776fe0846f21ab6c6728f1cbbbe6"

SRC_URI:append:class-target = " file://cross.patch"
SRC_URI:append:class-nativesdk = " file://cross.patch"

# Applies against virglrender < 0.6.0 and not qemu itself
CVE_CHECK_IGNORE += "CVE-2017-5957"

# The VNC server can expose host files uder some circumstances. We don't
# enable it by default.
CVE_CHECK_IGNORE += "CVE-2007-0998"

# 'The issues identified by this CVE were determined to not constitute a vulnerability.'
# https://bugzilla.redhat.com/show_bug.cgi?id=1609015#c11
CVE_CHECK_IGNORE += "CVE-2018-18438"

COMPATIBLE_HOST:mipsarchn32 = "null"
COMPATIBLE_HOST:mipsarchn64 = "null"
COMPATIBLE_HOST:riscv32 = "null"

# Per https://lists.nongnu.org/archive/html/qemu-devel/2020-09/msg03873.html
# upstream states qemu doesn't work without optimization
DEBUG_BUILD = "0"

do_install:append() {
    # Prevent QA warnings about installed ${localstatedir}/run
    if [ -d ${D}${localstatedir}/run ]; then rmdir ${D}${localstatedir}/run; fi
}

do_install_ptest() {
	cp -rL ${B}/tests ${D}${PTEST_PATH}
	find ${D}${PTEST_PATH}/tests -type f -name "*.[Sshcodp]" | xargs -i rm -rf {}

	# Don't check the file genreated by configure
	sed -i -e "1s,#!/usr/bin/bash,#!${base_bindir}/bash," ${D}${PTEST_PATH}/tests/data/acpi/disassemle-aml.sh

	# Strip the paths from the QEMU variable, we can use PATH
	sed -i -e "s#^QEMU=.*/qemu-#QEMU=qemu-#g" ${D}${PTEST_PATH}/tests/tcg/*.mak

	# Strip compiler flags as they break reproducibility
	sed -i -e "s,^CC=.*,CC=gcc," \
	       -e "s,^CCAS=.*,CCAS=gcc," \
	       -e "s,^LD=.*,LD=ld," ${D}${PTEST_PATH}/tests/tcg/*.mak

	# Update SRC_PATH variable to the right place on target
	sed -i -e "s#^SRC_PATH=.*#SRC_PATH=${PTEST_PATH}#g" ${D}${PTEST_PATH}/tests/tcg/*.mak

}

# QEMU_TARGETS is overridable variable
QEMU_TARGETS ?= "arm aarch64 i386 mips mipsel mips64 mips64el ppc ppc64 ppc64le riscv32 riscv64 sh4 x86_64"

EXTRA_OECONF = " \
    --prefix=${prefix} \
    --bindir=${bindir} \
    --includedir=${includedir} \
    --libdir=${libdir} \
    --mandir=${mandir} \
    --datadir=${datadir} \
    --docdir=${docdir}/${BPN} \
    --sysconfdir=${sysconfdir} \
    --libexecdir=${libexecdir} \
    --localstatedir=${localstatedir} \
    --with-suffix=${BPN} \
    --disable-strip \
    --disable-werror \
    --extra-cflags='${CFLAGS}' \
    --extra-ldflags='${LDFLAGS}' \
    --with-git=/bin/false \
    --with-git-submodules=ignore \
    --meson=meson \
    ${PACKAGECONFIG_CONFARGS} \
    "

B = "${WORKDIR}/build"

#EXTRA_OECONF:append = " --python=${HOSTTOOLS_DIR}/python3"

do_configure:prepend:class-native() {
	# Append build host pkg-config paths for native target since the host may provide sdl
	BHOST_PKGCONFIG_PATH=$(PATH=/usr/bin:/bin pkg-config --variable pc_path pkg-config || echo "")
	if [ ! -z "$BHOST_PKGCONFIG_PATH" ]; then
		export PKG_CONFIG_PATH=$PKG_CONFIG_PATH:$BHOST_PKGCONFIG_PATH
	fi
}

do_configure() {
    ${S}/configure ${EXTRA_OECONF}
}
do_configure[cleandirs] += "${B}"

do_install () {
	export STRIP=""
	oe_runmake 'DESTDIR=${D}' install
}

# The following fragment will create a wrapper for qemu-mips user emulation
# binary in order to work around a segmentation fault issue. Basically, by
# default, the reserved virtual address space for 32-on-64 bit is set to 4GB.
# This will trigger a MMU access fault in the virtual CPU. With this change,
# the qemu-mips works fine.
# IMPORTANT: This piece needs to be removed once the root cause is fixed!
do_install:append() {
	if [ -e "${D}/${bindir}/qemu-mips" ]; then
		create_wrapper ${D}/${bindir}/qemu-mips \
			QEMU_RESERVED_VA=0x0
	fi
}
# END of qemu-mips workaround

# Disable kvm/virgl/mesa on targets that do not support it
PACKAGECONFIG:remove:darwin = "kvm virglrenderer epoxy gtk+"
PACKAGECONFIG:remove:mingw32 = "kvm virglrenderer epoxy gtk+"

PACKAGECONFIG[sdl] = "--enable-sdl,--disable-sdl,libsdl2"
PACKAGECONFIG[virtfs] = "--enable-virtfs --enable-attr --enable-cap-ng,--disable-virtfs,libcap-ng attr,"
PACKAGECONFIG[aio] = "--enable-linux-aio,--disable-linux-aio,libaio,"
PACKAGECONFIG[uring] = "--enable-linux-io-uring,--disable-linux-io-uring,liburing"
PACKAGECONFIG[xen] = "--enable-xen,--disable-xen,xen-tools,xen-tools-libxenstore xen-tools-libxenctrl xen-tools-libxenguest"
PACKAGECONFIG[vnc-sasl] = "--enable-vnc --enable-vnc-sasl,--disable-vnc-sasl,cyrus-sasl,"
PACKAGECONFIG[vnc-jpeg] = "--enable-vnc --enable-vnc-jpeg,--disable-vnc-jpeg,jpeg,"
PACKAGECONFIG[libcurl] = "--enable-curl,--disable-curl,curl,"
PACKAGECONFIG[nss] = "--enable-smartcard,--disable-smartcard,nss,"
PACKAGECONFIG[curses] = "--enable-curses,--disable-curses,ncurses,"
PACKAGECONFIG[gtk+] = "--enable-gtk,--disable-gtk,gtk+3 gettext-native"
PACKAGECONFIG[vte] = "--enable-vte,--disable-vte,vte gettext-native"
PACKAGECONFIG[libcap-ng] = "--enable-cap-ng,--disable-cap-ng,libcap-ng,"
PACKAGECONFIG[ssh] = "--enable-libssh,--disable-libssh,libssh,"
PACKAGECONFIG[gcrypt] = "--enable-gcrypt,--disable-gcrypt,libgcrypt,"
PACKAGECONFIG[nettle] = "--enable-nettle,--disable-nettle,nettle"
PACKAGECONFIG[libusb] = "--enable-libusb,--disable-libusb,libusb1"
PACKAGECONFIG[fdt] = "--enable-fdt,--disable-fdt,dtc"
PACKAGECONFIG[alsa] = "--audio-drv-list=default,,alsa-lib"
PACKAGECONFIG[epoxy] = "--enable-opengl,--disable-opengl,libepoxy"
PACKAGECONFIG[lzo] = "--enable-lzo,--disable-lzo,lzo"
PACKAGECONFIG[numa] = "--enable-numa,--disable-numa,numactl"
PACKAGECONFIG[gnutls] = "--enable-gnutls,--disable-gnutls,gnutls"
PACKAGECONFIG[bzip2] = "--enable-bzip2,--disable-bzip2,bzip2"
PACKAGECONFIG[libiscsi] = "--enable-libiscsi,--disable-libiscsi"
PACKAGECONFIG[kvm] = "--enable-kvm,--disable-kvm"
PACKAGECONFIG[virglrenderer] = "--enable-virglrenderer,--disable-virglrenderer,virglrenderer"
# spice will be in meta-networking layer
PACKAGECONFIG[spice] = "--enable-spice,--disable-spice,spice"
# usbredir will be in meta-networking layer
PACKAGECONFIG[usb-redir] = "--enable-usb-redir,--disable-usb-redir,usbredir"
PACKAGECONFIG[snappy] = "--enable-snappy,--disable-snappy,snappy"
PACKAGECONFIG[glusterfs] = "--enable-glusterfs,--disable-glusterfs,glusterfs"
PACKAGECONFIG[xkbcommon] = "--enable-xkbcommon,--disable-xkbcommon,libxkbcommon"
PACKAGECONFIG[libudev] = "--enable-libudev,--disable-libudev,eudev"
PACKAGECONFIG[attr] = "--enable-attr,--disable-attr,attr,"
PACKAGECONFIG[rbd] = "--enable-rbd,--disable-rbd,ceph,ceph"
PACKAGECONFIG[vhost] = "--enable-vhost-net,--disable-vhost-net,,"
PACKAGECONFIG[ust] = "--enable-trace-backend=ust,--enable-trace-backend=nop,lttng-ust,"
PACKAGECONFIG[pie] = "--enable-pie,--disable-pie,,"
PACKAGECONFIG[seccomp] = "--enable-seccomp,--disable-seccomp,libseccomp"
# libnfs is currently provided by meta-kodi
PACKAGECONFIG[libnfs] = "--enable-libnfs,--disable-libnfs,libnfs"
PACKAGECONFIG[pmem] = "--enable-libpmem,--disable-libpmem,pmdk"
PACKAGECONFIG[pulsedio] = "--enable-pa,--disable-pa,pulseaudio"
PACKAGECONFIG[selinux] = "--enable-selinux,--disable-selinux"
PACKAGECONFIG[bpf] = "--enable-bpf,--disable-bpf,libbpf"
PACKAGECONFIG[capstone] = "--enable-capstone,--disable-capstone"
PACKAGECONFIG[rdma] = "--enable-rdma,--disable-rdma"
PACKAGECONFIG[vde] = "--enable-vde,--disable-vde"
PACKAGECONFIG[slirp] = "--enable-slirp=internal,--disable-slirp"
PACKAGECONFIG[brlapi] = "--enable-brlapi,--disable-brlapi"

INSANE_SKIP:${PN} = "arch"

FILES:${PN} += "${datadir}/icons"
