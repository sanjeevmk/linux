#ifndef __BTRFS_SYSFS__
#define __BTRFS_SYSFS__

int btrfs_create_device(struct kobject *super_kobj, u8 *uid);
int btrfs_kill_device(u8 *label);

/*
 * struct btrfs_kobject is defined to allow kobjects to be created under 
 * btrfs_kset and also the kobjects defined under btrfs_kset.
 * 
 * The #define to_btrfs_kobject(x) is used to get the pointer to the structure 
 * using the pointer to a member of the structure.
 * 
 * v1 Comment: As of now the struct contains just the kobject and a void pointer
 * The idea is that the void pointer can be put to use in certain cases without 
 * complicating the code.
 */
 /*
struct btrfs_kobject {
	struct kobject kobj;
	struct btrfs_kobject *head;
	struct btrfs_kobject *tail;
	int ref_count;
	int child_count;
	struct btrfs_kobject *first_child;
	struct kobject *super_kobj;
	void *ptr;
};
*/
#define to_btrfs_kobject(x) container_of(x, struct btrfs_kobject, kobj)

/* 
 * btrfs_kobject_attr lists the attributes for the struct btrfs_kobject
 * The attribute list contains the usual struct attribute and also two 
 * defined functions for showing and storing. This can be added on to.
 *
 * The #define to_btrfs_kobject_attr(x) is used to get the pointer to the 
 * structure using the pointer to a member of the structure.
 * 
 */
 /*
struct btrfs_kobject_attr {
	struct attribute attr;
	ssize_t (*show)(struct btrfs_kobject *kobj, \
			struct btrfs_kobject_attr *attr, char *buf);
	ssize_t (*store)(struct btrfs_kobject *kobj, \
			struct btrfs_kobject_attr *attr, const char *buf, size_t len);
};
*/
#define to_btrfs_kobject_attr(x) container_of(x, struct btrfs_kobject_attr,attr)

#endif
