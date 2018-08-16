#include <ntddk.h>
#include <wdf.h>
#include <excpt.h>
#include <windowsx.h>

extern void inline MainAsm(void);

VOID Unload(IN WDFDRIVER Driver)
{}



NTSTATUS Gs1DriverEntry(_In_ PDRIVER_OBJECT     DriverObject,
	_In_ PUNICODE_STRING    RegistryPath)
{

	// NTSTATUS variable to record success or failure
	NTSTATUS status = STATUS_SUCCESS;

	// Allocate the driver configuration object
	WDF_DRIVER_CONFIG config;

	WDF_DRIVER_CONFIG_INIT(
		&config,
		WDF_NO_EVENT_CALLBACK // This is a non-pnp driver.
	);

	config.EvtDriverUnload = Unload;
	MainAsm();


	return status;
}

