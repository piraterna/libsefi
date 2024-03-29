#ifndef EFI_PROTOCOLS_BOOT_MANAGER_POLICY_H
#define EFI_PROTOCOLS_BOOT_MANAGER_POLICY_H

#define EFI_BOOT_MANAGER_POLICY_PROTOCOL_GUID {0xfedf8e0c,0xe147,0x11e3, {0x99,0x03,0xb8,0xe8,0x56,0x2c,0xba,0xfa}}
#define EFI_BOOT_MANAGER_POLICY_CONSOLE_GUID {0xcab0e94c,0xe15f,0x11e3, {0x91,0x8d,0xb8,0xe8,0x56,0x2c,0xba,0xfa}}
#define EFI_BOOT_MANAGER_POLICY_NETWORK_GUID {0xd04159dc,0xe15f,0x11e3, {0xb2,0x61,0xb8,0xe8,0x56,0x2c,0xba,0xfa}}
#define EFI_BOOT_MANAGER_POLICY_CONNECT_ALL_GUID {0x113b2126, 0xfc8a, 0x11e3, {0xbd,0x6c,0xb8,0xe8,0x56,0x2c,0xba,0xfa}}

#define EFI_BOOT_MANAGER_POLICY_PROTOCOL_REVISION 0x00010000

typedef
EFI_STATUS
(EFIAPI *EFI_BOOT_MANAGER_POLICY_CONNECT_DEVICE_PATH)(
	IN EFI_BOOT_MANAGER_POLICY_PROTOCOL *This,
	IN EFI_DEVICE_PATH *DevicePath,
	IN BOOLEAN Recursive
);

typedef
EFI_STATUS
(EFIAPI *EFI_BOOT_MANAGER_POLICY_CONNECT_DEVICE_CLASS)(
	IN EFI_BOOT_MANAGER_POLICY_PROTOCOL *This,
	IN EFI_GUID *Class
);

typedef struct _EFI_BOOT_MANAGER_POLICY_PROTOCOL {
	UINT64 Revision;
	EFI_BOOT_MANAGER_POLICY_CONNECT_DEVICE_PATH ConnectDevicePath;
	EFI_BOOT_MANAGER_POLICY_CONNECT_DEVICE_CLASS ConnectDeviceClass;
} EFI_BOOT_MANAGER_POLICY_PROTOCOL;

#endif /* EFI_PROTOCOLS_BOOT_MANAGER_POLICY_H */
