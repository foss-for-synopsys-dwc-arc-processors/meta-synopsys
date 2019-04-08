FILESEXTRAPATHS_prepend := "${THISDIR}/weston:"
SRC_URI_append += "\
	file://1001-os-compatibility-define-CLOCK_BOOTTIME-when-not-avai.patch; \
	file://1005-protocol-add-weston-debug.xml.patch; \
	file://1006-libweston-add-weston_debug-API-and-implementation.patch; \
	file://1007-compositor-add-option-to-enable-weston_debug.patch; \
	file://1010-xwm-dump_property-to-use-FILE-internally.patch; \
	file://1011-xwm-move-FILE-to-the-callers-of-dump_property.patch; \
	file://1012-xwm-convert-WM_DEBUG-into-a-weston-debug-scope.patch; \
	file://1014-compositor-Add-weston_layer_mask_is_infinite.patch; \
	file://1015-compositor-Add-scene-graph-debug-scope.patch; \
	file://1017-compositor-drm-Add-backend-pointer-to-drm_output.patch; \
	file://1018-compositor-drm-Add-drm-backend-log-debug-scope.patch; \
	file://1046-compositor-drm-Read-FB2_MODIFIERS-capability.patch; \
"

