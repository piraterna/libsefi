#ifndef EFI_PROTOCOLS_DEVICE_PATH_H
#define EFI_PROTOCOLS_DEVICE_PATH_H

////
// EFI Device Path Protocol
///

#define EFI_DEVICE_PATH_PROTOCOL_GUID {0x09576e91,0x6d3f,0x11d2,{0x8e,0x39,0x00,0xa0,0xc9,0x69,0x72,0x3b}}

typedef struct _EFI_DEVICE_PATH_PROTOCOL EFI_DEVICE_PATH_PROTOCOL;
typedef struct _EFI_MEMMAP_DEVICE_PATH EFI_MEMMAP_DEVICE_PATH;

typedef struct _EFI_DEVICE_PATH_PROTOCOL {
	EFI_UINT8 Type;
	EFI_UINT8 SubType;
	EFI_UINT8 Length[2];
} EFI_DEVICE_PATH_PROTOCOL;

struct _EFI_MEMMAP_DEVICE_PATH
{
    EFI_DEVICE_PATH_PROTOCOL Header;
    EFI_UINT32 MemoryType;
    EFI_PHYSICAL_ADDRESS StartingAddress;
    EFI_PHYSICAL_ADDRESS EndingAddress;
};

////
// EFI Device Path Utilities Protocol
///

#define EFI_DEVICE_PATH_UTILITIES_PROTOCOL_GUID {0x379be4e,0xd706,0x437d, {0xb0,0x37,0xed,0xb8,0x2f,0xb7,0x72,0xa4}}

typedef struct _EFI_DEVICE_PATH_UTILITIES_PROTOCOL EFI_DEVICE_PATH_UTILITIES_PROTOCOL;

typedef
EFI_UINTN
(EFIAPI *EFI_DEVICE_PATH_UTILS_GET_DEVICE_PATH_SIZE)(
	IN CONST EFI_DEVICE_PATH_PROTOCOL *DevicePath
);

typedef
EFI_DEVICE_PATH_PROTOCOL*
(EFIAPI *EFI_DEVICE_PATH_UTILS_DUP_DEVICE_PATH)(
	IN CONST EFI_DEVICE_PATH_PROTOCOL *DevicePath
);

typedef
EFI_DEVICE_PATH_PROTOCOL*
(EFIAPI *EFI_DEVICE_PATH_UTILS_APPEND_PATH)(
	IN CONST EFI_DEVICE_PATH_PROTOCOL *Src1,
	IN CONST EFI_DEVICE_PATH_PROTOCOL *Src2
);

typedef
EFI_DEVICE_PATH_PROTOCOL*
(EFIAPI *EFI_DEVICE_PATH_UTILS_APPEND_NODE)(
	IN CONST EFI_DEVICE_PATH_PROTOCOL *DevicePath,
	IN CONST EFI_DEVICE_PATH_PROTOCOL *DeviceNode
);

typedef
EFI_DEVICE_PATH_PROTOCOL*
(EFIAPI *EFI_DEVICE_PATH_UTILS_APPEND_INSTANCE)(
	IN CONST EFI_DEVICE_PATH_PROTOCOL *DevicePath,
	IN CONST EFI_DEVICE_PATH_PROTOCOL *DevicePathInstance
);

typedef
EFI_DEVICE_PATH_PROTOCOL*
(EFIAPI *EFI_DEVICE_PATH_UTILS_GET_NEXT_INSTANCE)(
	IN OUT EFI_DEVICE_PATH_PROTOCOL **DevicePathInstance,
	OUT EFI_UINTN *DevicePathInstanceSize OPTIONAL
);

typedef
EFI_BOOLEAN
(EFIAPI *EFI_DEVICE_PATH_UTILS_IS_MULTI_INSTANCE)(
	IN CONST EFI_DEVICE_PATH_PROTOCOL *DevicePath
);

typedef
EFI_DEVICE_PATH_PROTOCOL*
(EFIAPI *EFI_DEVICE_PATH_UTILS_CREATE_NODE)(
	IN EFI_UINT8 NodeType,
	IN EFI_UINT8 NodeSubType,
	IN EFI_UINT16 NodeLength
);

typedef struct _EFI_DEVICE_PATH_UTILITIES_PROTOCOL {
	EFI_DEVICE_PATH_UTILS_GET_DEVICE_PATH_SIZE GetDevicePathSize;
	EFI_DEVICE_PATH_UTILS_DUP_DEVICE_PATH DuplicateDevicePath;
	EFI_DEVICE_PATH_UTILS_APPEND_PATH AppendDevicePath;
	EFI_DEVICE_PATH_UTILS_APPEND_NODE AppendDeviceNode;
	EFI_DEVICE_PATH_UTILS_APPEND_INSTANCE AppendDevicePathInstance;
	EFI_DEVICE_PATH_UTILS_GET_NEXT_INSTANCE GetNextDevicePathInstance;
	EFI_DEVICE_PATH_UTILS_IS_MULTI_INSTANCE IsDevicePathMultiInstance;
	EFI_DEVICE_PATH_UTILS_CREATE_NODE CreateDeviceNode;
} EFI_DEVICE_PATH_UTILITIES_PROTOCOL;

#endif /* EFI_PROTOCOLS_DEVICE_PATH_H */
