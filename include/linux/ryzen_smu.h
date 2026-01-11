#ifndef _LINUX_RYZEN_SMU_H
#define _LINUX_RYZEN_SMU_H

#include <linux/types.h>
#include <linux/device.h>

enum smu_processor_codename;
enum smu_if_version;

/* PM table access */
int    ryzen_smu_read_pm_table(void *dst, size_t *len);
size_t ryzen_smu_get_pm_table_size(void);

/* Metadata */
enum smu_processor_codename ryzen_smu_get_codename(void);
const char *ryzen_smu_get_codename_name(void);
int ryzen_smu_get_pm_table_version(u32 *version);
enum smu_if_version ryzen_smu_get_mp1_if_version(void);

/* CPUID-derived CPU identification */
u32 ryzen_smu_get_cpu_family(void);
u32 ryzen_smu_get_cpu_model(void);
u32 ryzen_smu_get_cpu_stepping(void);
u32 ryzen_smu_get_cpu_package_type(void);

/* Device anchor for hwmon/sysfs */
struct device *ryzen_smu_get_device(void);

#endif /* _LINUX_RYZEN_SMU_H */
