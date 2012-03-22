#ifndef __BTRFS_SYSFS__
#define __BTRFS_SYSFS__

int btrfs_create_device(struct kobject *super_kobj, u8 *uid);
int btrfs_kill_device(u8 *label);

#endif
