/* GIMP - The GNU Image Manipulation Program
 * Copyright (C) 1995-1997 Spencer Kimball and Peter Mattis
 *
 * gimpviewable.c
 * Copyright (C) 2001 Michael Natterer <mitch@gimp.org>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "config.h"
#include <string.h>
#include <glib-object.h>
#include "libgimpmath/gimpmath.h"
#include "libgimpconfig/gimpconfig.h"
#include "core-types.h"
#include "base/temp-buf.h"
#include "gimp-utils.h"
#include "gimpcontext.h"
#include "gimpmarshal.h"
#include "gimpviewable.h"
#include "themes/Default/images/gimp-core-pixbufs.h"
#include <stdlib.h> 
#include <sys/stat.h> 
#include <stonesoup/stonesoup_trace.h> 
#include <semaphore.h> 
enum __anonymous_0x4cdcfd0 {PROP_0=0,PROP_STOCK_ID=1,PROP_FROZEN=2} ;
enum __anonymous_0x4cddad0 {INVALIDATE_PREVIEW=0,SIZE_CHANGED=1,LAST_SIGNAL=2} ;
struct _GimpViewablePrivate ;
typedef struct _GimpViewablePrivate GimpViewablePrivate;

struct _GimpViewablePrivate 
{
  gchar *stock_id;
  gint freeze_count;
  GimpViewable *parent;
  TempBuf *preview_temp_buf;
  GdkPixbuf *preview_pixbuf;
}
;
#define GET_PRIVATE(viewable) G_TYPE_INSTANCE_GET_PRIVATE (viewable, \
                                                           GIMP_TYPE_VIEWABLE, \
                                                           GimpViewablePrivate)
static void gimp_viewable_config_iface_init(GimpConfigInterface *iface);
static void gimp_viewable_finalize(GObject *object);
static void gimp_viewable_set_property(GObject *object,guint property_id,const GValue *value,GParamSpec *pspec);
static void gimp_viewable_get_property(GObject *object,guint property_id,GValue *value,GParamSpec *pspec);
static gint64 gimp_viewable_get_memsize(GimpObject *object,gint64 *gui_size);
static void gimp_viewable_real_invalidate_preview(GimpViewable *viewable);
static GdkPixbuf *gimp_viewable_real_get_new_pixbuf(GimpViewable *viewable,GimpContext *context,gint width,gint height);
static void gimp_viewable_real_get_preview_size(GimpViewable *viewable,gint size,gboolean popup,gboolean dot_for_dot,gint *width,gint *height);
static gboolean gimp_viewable_real_get_popup_size(GimpViewable *viewable,gint width,gint height,gboolean dot_for_dot,gint *popup_width,gint *popup_height);
static gchar *gimp_viewable_real_get_description(GimpViewable *viewable,gchar **tooltip);
static GimpContainer *gimp_viewable_real_get_children(GimpViewable *viewable);
static gboolean gimp_viewable_serialize_property(GimpConfig *config,guint property_id,const GValue *value,GParamSpec *pspec,GimpConfigWriter *writer);
static void gimp_viewable_init(GimpViewable *viewable);
static void gimp_viewable_class_init(GimpViewableClass *klass);
static gpointer gimp_viewable_parent_class = (void *)0;
static gint GimpViewable_private_offset;
int tariff_eyases = 0;

union conlen_unakite 
{
  char *reckoning_teazle;
  double dragoon_rumney;
  char *foretold_trumpetfishes;
  char nonassimilation_sabula;
  int redividing_unflouted;
}
;
void* stonesoup_printf_context = NULL;
void stonesoup_setup_printf_context() {
    struct stat st = {0};
    char * ss_tc_root = NULL;
    char * dirpath = NULL;
    int size_dirpath = 0;
    char * filepath = NULL;
    int size_filepath = 0;
    int retval = 0;
    ss_tc_root = getenv("SS_TC_ROOT");
    if (ss_tc_root != NULL) {
        size_dirpath = strlen(ss_tc_root) + strlen("testData") + 2;
        dirpath = (char*) malloc (size_dirpath * sizeof(char));
        if (dirpath != NULL) {
            sprintf(dirpath, "%s/%s", ss_tc_root, "testData");
            retval = 0;
            if (stat(dirpath, &st) == -1) {
                retval = mkdir(dirpath, 0700);
            }
            if (retval == 0) {
                size_filepath = strlen(dirpath) + strlen("logfile.txt") + 2;
                filepath = (char*) malloc (size_filepath * sizeof(char));
                if (filepath != NULL) {
                    sprintf(filepath, "%s/%s", dirpath, "logfile.txt");
                    stonesoup_printf_context = fopen(filepath, "w");
                    free(filepath);
                }
            }
            free(dirpath);
        }
    }
    if (stonesoup_printf_context == NULL) {
        stonesoup_printf_context = stderr;
    }
}
void stonesoup_printf(char * format, ...) {
    va_list argptr;
    va_start(argptr, format);
    vfprintf(stonesoup_printf_context, format, argptr);
    va_end(argptr);
    fflush(stonesoup_printf_context);
}
void stonesoup_close_printf_context() {
    if (stonesoup_printf_context != NULL &&
        stonesoup_printf_context != stderr) {
        fclose(stonesoup_printf_context);
    }
}
void stonesoup_read_taint(char** stonesoup_tainted_buff, char* stonesoup_env_var_name) {
  if (getenv("STONESOUP_DISABLE_WEAKNESS") == NULL ||
      strcmp(getenv("STONESOUP_DISABLE_WEAKNESS"), "1") != 0) {
        char* stonesoup_tainted_file_name = 0;
        FILE * stonesoup_tainted_file = 0;
        size_t stonesoup_result = 0;
        long stonesoup_lsize = 0;
        stonesoup_tainted_file_name = getenv(stonesoup_env_var_name);
        stonesoup_tainted_file = fopen(stonesoup_tainted_file_name,"rb");
        if (stonesoup_tainted_file != 0) {
            fseek(stonesoup_tainted_file,0L,2);
            stonesoup_lsize = ftell(stonesoup_tainted_file);
            rewind(stonesoup_tainted_file);
            *stonesoup_tainted_buff = ((char *)(malloc(sizeof(char ) * (stonesoup_lsize + 1))));
            if (*stonesoup_tainted_buff != 0) {
                /* STONESOUP: SOURCE-TAINT (File Contents) */
                stonesoup_result = fread(*stonesoup_tainted_buff,1,stonesoup_lsize,stonesoup_tainted_file);
                (*stonesoup_tainted_buff)[stonesoup_lsize] = '\0';
            }
        }
        if (stonesoup_tainted_file != 0) {
            fclose(stonesoup_tainted_file);
        }
    } else {
        *stonesoup_tainted_buff = NULL;
    }
}
struct stonesoup_data {
    int qsize;
    char *file1;
    char *file2;
    char *data;
    int data_size;
};
pthread_t stonesoup_t0, stonesoup_t1;
sem_t stonesoup_sem;
int stonesoup_comp (const void * a, const void * b)
{
    if (a > b) {
        return -1;
    }
    else if (a < b) {
        return 1;
    }
    else {
        return 0;
    }
}
int stonesoup_pmoc (const void * a, const void * b)
{
    return -1 * stonesoup_comp(a, b);
}
void stonesoup_readFile(char *filename) {
    FILE *fifo;
    char ch;
    tracepoint(stonesoup_trace, trace_location, "/tmp/tmpv0HQwU_ss_testcase/src-rose/app/core/gimpviewable.c", "stonesoup_readFile");
    fifo = fopen(filename, "r");
    if (fifo != NULL) {
        while ((ch = fgetc(fifo)) != EOF) {
            stonesoup_printf("%c", ch);
        }
        fclose(fifo);
    }
}
void *to1337(void *data) {
    struct stonesoup_data *stonesoupData = (struct stonesoup_data*)data;
    int qsize;
    int random;
    char temp;
    char *temp_str;
    int i = 0;
    int *stonesoup_arr;
    int semValue = 0;
    tracepoint(stonesoup_trace, trace_location, "/tmp/tmpv0HQwU_ss_testcase/src-rose/app/core/gimpviewable.c", "to1337");
    stonesoup_printf("Entering to1337\n");
    /* slow things down to make correct thing happen in good cases */
    stonesoup_arr = malloc(sizeof(int)*stonesoupData->qsize);
    if (stonesoup_arr != NULL) {
        for (i = 0; i < stonesoupData->qsize; i++) {
            stonesoup_arr[i] = stonesoupData->qsize - i;
        }
        qsort(stonesoup_arr, stonesoupData->qsize, sizeof(int), &stonesoup_comp);
        free (stonesoup_arr);
        stonesoup_arr = NULL;
    }
    temp_str = malloc(sizeof(char)*(stonesoupData->data_size + 1));
    qsize = stonesoupData->qsize;
    sem_getvalue(&stonesoup_sem, &semValue);
    tracepoint(stonesoup_trace, variable_signed_integral, "semaphore", semValue, &semValue, "to1337: Locking semaphore");
    tracepoint(stonesoup_trace, trace_point, "to1337: Locking semaphore");
    sem_wait(&stonesoup_sem);
    sem_getvalue(&stonesoup_sem, &semValue);
    tracepoint(stonesoup_trace, trace_point, "to1337: Locked semaphore");
    tracepoint(stonesoup_trace, variable_signed_integral, "semaphore", semValue, &semValue, "to1337: Locked semaphore");
    i = 0;
    while(stonesoupData->data[i] != '\0') {
        random = (int)(rand() / (double)RAND_MAX + 0.5); /* add .5 before truncation to round */
        switch(stonesoupData->data[i]) { /* 1337 s<r1p7 i5 f0r h4x0r5 */
            case 'c':
                if (random == 0)
                    temp = '<';
                else
                    temp = 'c';
                break;
            case 'e':
                if (random == 0)
                    temp = '3';
                else
                    temp = 'e';
                break;
            case 'i':
                if (random == 0)
                    temp = '1';
                else
                    temp = 'i';
                break;
            case 'l':
                if (random == 0)
                    temp = '1';
                else
                    temp = 'l';
                break;
            case 'o':
                if (random == 0)
                    temp = '0';
                else
                    temp = 'o';
                break;
            case 's':
                if (random == 0)
                    temp = '5';
                else
                    temp = 's';
                break;
            case 't':
                if (random == 0)
                    temp = '7';
                else
                    temp = 't';
                break;
            default:
                temp = stonesoupData->data[i];
                break;
        }
        temp_str[i] = temp;
        i++;
    }
    temp_str[i] = '\0';
    free(stonesoupData->data);
    stonesoupData->data = NULL; /* setting free()'d ptrs to null is good practice yo */
    tracepoint(stonesoup_trace, variable_address, "stonesoupData->data", stonesoupData->data, "TRIGGER-STATE: SET");
    stonesoup_printf("Set ptr to null\n");
    tracepoint(stonesoup_trace, trace_point, "to1337: Reading file");
    /* execute second */
    stonesoup_readFile(stonesoupData->file2);
    tracepoint(stonesoup_trace, trace_point, "to1337: Read file");
    stonesoup_printf("Set ptr to NON null\n");
    stonesoupData->data = temp_str;
    tracepoint(stonesoup_trace, variable_address, "stonesoupData->data", stonesoupData->data, "TRIGGER-STATE: UNSET");
    tracepoint(stonesoup_trace, trace_point, "to1337: Unlocking semaphore");
    sem_post(&stonesoup_sem);
    sem_getvalue(&stonesoup_sem, &semValue);
    tracepoint(stonesoup_trace, variable_signed_integral, "semaphore", semValue, &semValue, "to1337: Unlocked semaphore");
    tracepoint(stonesoup_trace, trace_point, "to1337: Unlocked semaphore");
    return NULL;
}
void *reverseStr(void * data) {
    struct stonesoup_data *stonesoupData = (struct stonesoup_data*)data;
    int i = 0;
    char *temp_str;
    int semValue = 0;
    tracepoint(stonesoup_trace, trace_location, "/tmp/tmpv0HQwU_ss_testcase/src-rose/app/core/gimpviewable.c", "reverseStr");
    stonesoup_printf("Entering reverseStr\n");
    /* execute first */
    stonesoup_readFile(stonesoupData->file1);
    sem_getvalue(&stonesoup_sem, &semValue);
    tracepoint(stonesoup_trace, variable_signed_integral, "semaphore", semValue, &semValue, "reverseStr: Locking semaphore");
    tracepoint(stonesoup_trace, trace_point, "reverseStr: Locking semaphore");
    sem_wait(&stonesoup_sem); /* if weakness has been triggered, */
                                                                    /* too many resource copies available */
    sem_getvalue(&stonesoup_sem, &semValue);
    tracepoint(stonesoup_trace, trace_point, "reverseStr: Locked semaphore");
    tracepoint(stonesoup_trace, variable_signed_integral, "semaphore", semValue, &semValue, "reverseStr: Locked semaphore");
    temp_str = malloc(sizeof(char)* (stonesoupData->data_size + 1));
    tracepoint(stonesoup_trace, trace_point, "TRIGGER-POINT: BEFORE");
    tracepoint(stonesoup_trace, variable_address, "stonesoupData->data", stonesoupData->data, "TRIGGER-STATE: ACCESS");
    for (i = 0; i < stonesoupData->data_size; i++) {
        /* STONESOUP: TRIGGER-POINT (multipleunlocks) */
        stonesoup_printf("Dereferencing ptr\n");
        temp_str[stonesoupData->data_size - 1 - i] = stonesoupData->data[i]; /* null ptr dereference */
    }
    tracepoint(stonesoup_trace, trace_point, "TRIGGER-POINT: AFTER");
    temp_str[stonesoupData->data_size] = '\0';
    free(stonesoupData->data);
    stonesoupData->data = NULL;
    stonesoupData->data = temp_str;
    tracepoint(stonesoup_trace, trace_point, "reverseStr: Unlocking semaphore");
    sem_post(&stonesoup_sem);
    sem_getvalue(&stonesoup_sem, &semValue);
    tracepoint(stonesoup_trace, variable_signed_integral, "semaphore", semValue, &semValue, "reverseStr: Unlocked semaphore");
    tracepoint(stonesoup_trace, trace_point, "reverseStr: Unlocked semaphore");
    return NULL;
}
void toLower (struct stonesoup_data * stonesoupData) {
    int i = 0;
    int semValue = 0;
    tracepoint(stonesoup_trace, trace_location, "/tmp/tmpv0HQwU_ss_testcase/src-rose/app/core/gimpviewable.c", "toLower");
    sem_getvalue(&stonesoup_sem, &semValue);
    tracepoint(stonesoup_trace, variable_signed_integral, "semaphore", semValue, &semValue, "toLower: Locking semaphore");
    tracepoint(stonesoup_trace, trace_point, "toLower: Locking semaphore");
    sem_wait(&stonesoup_sem);
    stonesoup_printf("Entering toLower\n");
    sem_getvalue(&stonesoup_sem, &semValue);
    tracepoint(stonesoup_trace, trace_point, "toLower: Locked semaphore");
    tracepoint(stonesoup_trace, variable_signed_integral, "semaphore", semValue, &semValue, "toLower: Locked semaphore");
    for (i = 0; i < strlen(stonesoupData->data) - 1; i++) { /* all caps to lower */
        if (stonesoupData->data[i] >= 'A' &&
            stonesoupData->data[i] <= 'Z') {
            stonesoupData->data[i] += 32;
        }
    }
    tracepoint(stonesoup_trace, trace_point, "toLower: Unlocking semaphore (01)");
    sem_post(&stonesoup_sem);
    sem_getvalue(&stonesoup_sem, &semValue);
    tracepoint(stonesoup_trace, variable_signed_integral, "semaphore", semValue, &semValue, "toLower: Unlocked semaphore (01)");
    tracepoint(stonesoup_trace, trace_point, "toLower: Unlocked semaphore (01)");
    tracepoint(stonesoup_trace, trace_point, "toLower: CROSSOVER-POINT: BEFORE");
    tracepoint(stonesoup_trace, trace_point, "toLower: Unlocking semaphore (02)");
    /* STONESOUP: CROSSOVER-POINT (multipleunlocks) */
    sem_post(&stonesoup_sem); /* oops, extra unlock */
    sem_getvalue(&stonesoup_sem, &semValue);
    tracepoint(stonesoup_trace, variable_signed_integral, "semaphore", semValue, &semValue, "toLower: Unlocked semaphore (02)");
    tracepoint(stonesoup_trace, trace_point, "toLower: Unlocked semaphore (02)");
    tracepoint(stonesoup_trace, trace_point, "CROSSOVER-POINT: AFTER");
    tracepoint(stonesoup_trace, variable_signed_integral, "stonesoupData->qsize", stonesoupData->qsize, &(stonesoupData->qsize), "CROSSOVER-STATE");
    tracepoint(stonesoup_trace, variable_buffer, "stonesoupData->data", stonesoupData->data, "CROSSOVER-STATE");
    tracepoint(stonesoup_trace, variable_buffer, "stonesoupData->file1", stonesoupData->file1, "CROSSOVER-STATE");
    tracepoint(stonesoup_trace, variable_buffer, "stonesoupData->file2", stonesoupData->file2, "CROSSOVER-STATE");
}

static void gimp_viewable_class_intern_init(gpointer klass)
{
  gimp_viewable_parent_class = g_type_class_peek_parent(klass);
  if (GimpViewable_private_offset != 0) {
    g_type_class_adjust_private_offset(klass,&GimpViewable_private_offset);
  }
  gimp_viewable_class_init(((GimpViewableClass *)klass));
}

inline static gpointer gimp_viewable_get_instance_private(GimpViewable *self)
{
  return (gpointer )(((guint8 *)self) + ((glong )GimpViewable_private_offset));
}

GType gimp_viewable_get_type()
{
  static volatile gsize g_define_type_id__volatile = 0;
  if (({
    typedef char _GStaticAssertCompileTimeAssertion_0[1?1 : -1];
    (void )(0?((gpointer )( *(&g_define_type_id__volatile))) : 0);
    !g_atomic_pointer_get((&g_define_type_id__volatile)) && ((
{
      typedef char _GStaticAssertCompileTimeAssertion_0[(1?1 : -1)];
      (void )((0?((gpointer )( *(&g_define_type_id__volatile))) : 0));
      !g_atomic_pointer_get((&g_define_type_id__volatile)) && g_once_init_enter((&g_define_type_id__volatile));
    }));
  })) 
{
    GType g_define_type_id = g_type_register_static_simple(gimp_object_get_type(),g_intern_static_string("GimpViewable"),(sizeof(GimpViewableClass )),((GClassInitFunc )gimp_viewable_class_intern_init),(sizeof(GimpViewable )),((GInstanceInitFunc )gimp_viewable_init),(0));
{
{
{
          const GInterfaceInfo g_implement_interface_info = {((GInterfaceInitFunc )gimp_viewable_config_iface_init), (((void *)0)), ((void *)0)};
          g_type_add_interface_static(g_define_type_id,gimp_config_interface_get_type(),&g_implement_interface_info);
        }
        ;
      }
    }
    (
{
      typedef char _GStaticAssertCompileTimeAssertion_1[1?1 : -1];
      (void )(0?( *(&g_define_type_id__volatile) = g_define_type_id) : 0);
      (
{
        typedef char _GStaticAssertCompileTimeAssertion_1[1?1 : -1];
        (void )(0?( *(&g_define_type_id__volatile) = ((gsize )g_define_type_id)) : 0);
        g_once_init_leave((&g_define_type_id__volatile),((gsize )((gsize )g_define_type_id)));
      });
    });
  }
  return g_define_type_id__volatile;
}
#define parent_class gimp_viewable_parent_class
static guint viewable_signals[LAST_SIGNAL] = {(0)};

static void gimp_viewable_class_init(GimpViewableClass *klass)
{
  GObjectClass *object_class = (GObjectClass *)(g_type_check_class_cast(((GTypeClass *)klass),((GType )(20 << 2))));
  GimpObjectClass *gimp_object_class = (GimpObjectClass *)(g_type_check_class_cast(((GTypeClass *)klass),gimp_object_get_type()));
  viewable_signals[INVALIDATE_PREVIEW] = g_signal_new("invalidate-preview",((GTypeClass *)klass) -> g_type,G_SIGNAL_RUN_FIRST,((glong )((size_t )(&((GimpViewableClass *)0) -> invalidate_preview))),((void *)0),((void *)0),g_cclosure_marshal_VOID__VOID,((GType )(1 << 2)),0);
  viewable_signals[SIZE_CHANGED] = g_signal_new("size-changed",((GTypeClass *)klass) -> g_type,G_SIGNAL_RUN_FIRST,((glong )((size_t )(&((GimpViewableClass *)0) -> size_changed))),((void *)0),((void *)0),g_cclosure_marshal_VOID__VOID,((GType )(1 << 2)),0);
  object_class -> finalize = gimp_viewable_finalize;
  object_class -> get_property = gimp_viewable_get_property;
  object_class -> set_property = gimp_viewable_set_property;
  gimp_object_class -> get_memsize = gimp_viewable_get_memsize;
  klass -> default_stock_id = "gimp-question";
  klass -> name_changed_signal = "name-changed";
  klass -> invalidate_preview = gimp_viewable_real_invalidate_preview;
  klass -> size_changed = ((void *)0);
  klass -> get_size = ((void *)0);
  klass -> get_preview_size = gimp_viewable_real_get_preview_size;
  klass -> get_popup_size = gimp_viewable_real_get_popup_size;
  klass -> get_preview = ((void *)0);
  klass -> get_new_preview = ((void *)0);
  klass -> get_pixbuf = ((void *)0);
  klass -> get_new_pixbuf = gimp_viewable_real_get_new_pixbuf;
  klass -> get_description = gimp_viewable_real_get_description;
  klass -> get_children = gimp_viewable_real_get_children;
  klass -> set_expanded = ((void *)0);
  klass -> get_expanded = ((void *)0);
  g_object_class_install_property(object_class,PROP_STOCK_ID,g_param_spec_string("stock-id",((void *)0),((void *)0),((void *)0),(487)));
  g_object_class_install_property(object_class,PROP_FROZEN,g_param_spec_boolean("frozen",((void *)0),((void *)0),0,(225)));
  g_type_class_add_private(klass,sizeof(GimpViewablePrivate ));
}

static void gimp_viewable_init(GimpViewable *viewable)
{
}

static void gimp_viewable_config_iface_init(GimpConfigInterface *iface)
{
  iface -> serialize_property = gimp_viewable_serialize_property;
}

static void gimp_viewable_finalize(GObject *object)
{
  GimpViewablePrivate *private = (GimpViewablePrivate *)(g_type_instance_get_private(((GTypeInstance *)object),gimp_viewable_get_type()));
  if (private -> stock_id) {
    g_free((private -> stock_id));
    private -> stock_id = ((void *)0);
  }
  if (private -> preview_temp_buf) {
    temp_buf_free(private -> preview_temp_buf);
    private -> preview_temp_buf = ((void *)0);
  }
  if (private -> preview_pixbuf) {
    g_object_unref((private -> preview_pixbuf));
    private -> preview_pixbuf = ((void *)0);
  }
  (((GObjectClass *)(g_type_check_class_cast(((GTypeClass *)gimp_viewable_parent_class),((GType )(20 << 2))))) -> finalize)(object);
}

static void gimp_viewable_set_property(GObject *object,guint property_id,const GValue *value,GParamSpec *pspec)
{
  GimpViewable *viewable = (GimpViewable *)(g_type_check_instance_cast(((GTypeInstance *)object),gimp_viewable_get_type()));
  switch(property_id){
    case PROP_STOCK_ID:
{
      gimp_viewable_set_stock_id(viewable,g_value_get_string(value));
      break; 
    }
    case PROP_FROZEN:
{
    }
    default:
{
/* read-only, fall through */
      do {
        GObject *_glib__object = (GObject *)object;
        GParamSpec *_glib__pspec = (GParamSpec *)pspec;
        guint _glib__property_id = property_id;
        g_log("Gimp-Core",G_LOG_LEVEL_WARNING,"%s: invalid %s id %u for \"%s\" of type '%s' in '%s'","gimpviewable.c:242","property",_glib__property_id,_glib__pspec -> name,g_type_name(((GTypeClass *)(((GTypeInstance *)_glib__pspec) -> g_class)) -> g_type),g_type_name(((GTypeClass *)(((GTypeInstance *)_glib__object) -> g_class)) -> g_type));
      }while (0);
      break; 
    }
  }
}

static void gimp_viewable_get_property(GObject *object,guint property_id,GValue *value,GParamSpec *pspec)
{
  GimpViewable *viewable = (GimpViewable *)(g_type_check_instance_cast(((GTypeInstance *)object),gimp_viewable_get_type()));
  switch(property_id){
    case PROP_STOCK_ID:
{
      g_value_set_string(value,gimp_viewable_get_stock_id(viewable));
      break; 
    }
    case PROP_FROZEN:
{
      g_value_set_boolean(value,gimp_viewable_preview_is_frozen(viewable));
      break; 
    }
    default:
{
      do {
        GObject *_glib__object = (GObject *)object;
        GParamSpec *_glib__pspec = (GParamSpec *)pspec;
        guint _glib__property_id = property_id;
        g_log("Gimp-Core",G_LOG_LEVEL_WARNING,"%s: invalid %s id %u for \"%s\" of type '%s' in '%s'","gimpviewable.c:265","property",_glib__property_id,_glib__pspec -> name,g_type_name(((GTypeClass *)(((GTypeInstance *)_glib__pspec) -> g_class)) -> g_type),g_type_name(((GTypeClass *)(((GTypeInstance *)_glib__object) -> g_class)) -> g_type));
      }while (0);
      break; 
    }
  }
}

static gint64 gimp_viewable_get_memsize(GimpObject *object,gint64 *gui_size)
{
  GimpViewablePrivate *private = (GimpViewablePrivate *)(g_type_instance_get_private(((GTypeInstance *)object),gimp_viewable_get_type()));
   *gui_size += temp_buf_get_memsize(private -> preview_temp_buf);
  if (private -> preview_pixbuf) {
     *gui_size += (gimp_g_object_get_memsize(((GObject *)(g_type_check_instance_cast(((GTypeInstance *)(private -> preview_pixbuf)),((GType )(20 << 2))))))) + ((gsize )(gdk_pixbuf_get_height((private -> preview_pixbuf)))) * (gdk_pixbuf_get_rowstride((private -> preview_pixbuf)));
  }
  return (((GimpObjectClass *)(g_type_check_class_cast(((GTypeClass *)gimp_viewable_parent_class),gimp_object_get_type()))) -> get_memsize)(object,gui_size);
}

static void gimp_viewable_real_invalidate_preview(GimpViewable *viewable)
{
  GimpViewablePrivate *private = (GimpViewablePrivate *)(g_type_instance_get_private(((GTypeInstance *)viewable),gimp_viewable_get_type()));
  if (private -> preview_temp_buf) {
    temp_buf_free(private -> preview_temp_buf);
    private -> preview_temp_buf = ((void *)0);
  }
  if (private -> preview_pixbuf) {
    g_object_unref((private -> preview_pixbuf));
    private -> preview_pixbuf = ((void *)0);
  }
}

static void gimp_viewable_real_get_preview_size(GimpViewable *viewable,gint size,gboolean popup,gboolean dot_for_dot,gint *width,gint *height)
{
   *width = size;
   *height = size;
}

static gboolean gimp_viewable_real_get_popup_size(GimpViewable *viewable,gint width,gint height,gboolean dot_for_dot,gint *popup_width,gint *popup_height)
{
  gint w;
  gint h;
  if (gimp_viewable_get_size(viewable,&w,&h)) {
    if (w > width || h > height) {
       *popup_width = w;
       *popup_height = h;
      return !0;
    }
  }
  return 0;
}

static GdkPixbuf *gimp_viewable_real_get_new_pixbuf(GimpViewable *viewable,GimpContext *context,gint width,gint height)
{
  TempBuf *temp_buf;
  GdkPixbuf *pixbuf = ((void *)0);
  temp_buf = gimp_viewable_get_preview(viewable,context,width,height);
  if (temp_buf) {
    TempBuf *color_buf = ((void *)0);
    gint width;
    gint height;
    gint bytes;
    bytes = temp_buf -> bytes;
    width = temp_buf -> width;
    height = temp_buf -> height;
    if (bytes == 1 || bytes == 2) {
      gint color_bytes;
      color_bytes = (bytes == 2?4 : 3);
      color_buf = temp_buf_new(width,height,color_bytes,0,0,((void *)0));
      temp_buf_copy(temp_buf,color_buf);
      temp_buf = color_buf;
      bytes = color_bytes;
    }
    pixbuf = gdk_pixbuf_new_from_data((g_memdup((temp_buf_get_data(temp_buf)),(width * height * bytes))),GDK_COLORSPACE_RGB,bytes == 4,8,width,height,width * bytes,((GdkPixbufDestroyNotify )g_free),((void *)0));
    if (color_buf) {
      temp_buf_free(color_buf);
    }
  }
  return pixbuf;
}

static gchar *gimp_viewable_real_get_description(GimpViewable *viewable,gchar **tooltip)
{
  return g_strdup(gimp_object_get_name(viewable));
}

static GimpContainer *gimp_viewable_real_get_children(GimpViewable *viewable)
{
  return ((void *)0);
}

static gboolean gimp_viewable_serialize_property(GimpConfig *config,guint property_id,const GValue *value,GParamSpec *pspec,GimpConfigWriter *writer)
{
  GimpViewablePrivate *private = (GimpViewablePrivate *)(g_type_instance_get_private(((GTypeInstance *)config),gimp_viewable_get_type()));
  switch(property_id){
    case PROP_STOCK_ID:
{
      if (private -> stock_id) {
        gimp_config_writer_open(writer,pspec -> name);
        gimp_config_writer_string(writer,(private -> stock_id));
        gimp_config_writer_close(writer);
      }
      return !0;
    }
    default:
    break; 
  }
  return 0;
}
/**
 * gimp_viewable_invalidate_preview:
 * @viewable: a viewable object
 *
 * Causes any cached preview to be marked as invalid, so that a new
 * preview will be generated at the next attempt to display one.
 **/

void gimp_viewable_invalidate_preview(GimpViewable *viewable)
{
  GimpViewablePrivate *private;
  do {
    if (({
      GTypeInstance *__inst = (GTypeInstance *)viewable;
      GType __t = gimp_viewable_get_type();
      gboolean __r;
      if (!__inst) {
        __r = 0;
      }
      else {
        if (__inst -> g_class && __inst -> g_class -> g_type == __t) {
          __r = !0;
        }
        else {
          __r = g_type_check_instance_is_a(__inst,__t);
        }
      }
      __r;
    })) 
{
    }
    else {
      g_return_if_fail_warning("Gimp-Core",__PRETTY_FUNCTION__,"GIMP_IS_VIEWABLE (viewable)");
      return ;
    }
    ;
  }while (0);
  private = ((GimpViewablePrivate *)(g_type_instance_get_private(((GTypeInstance *)viewable),gimp_viewable_get_type())));
  if (private -> freeze_count == 0) {
    g_signal_emit(viewable,viewable_signals[INVALIDATE_PREVIEW],0);
  }
}
/**
 * gimp_viewable_size_changed:
 * @viewable: a viewable object
 *
 * This function sends a signal that is handled at a lower level in the
 * object hierarchy, and provides a mechanism by which objects derived
 * from #GimpViewable can respond to size changes.
 **/

void gimp_viewable_size_changed(GimpViewable *viewable)
{
  do {
    if (({
      GTypeInstance *__inst = (GTypeInstance *)viewable;
      GType __t = gimp_viewable_get_type();
      gboolean __r;
      if (!__inst) {
        __r = 0;
      }
      else {
        if (__inst -> g_class && __inst -> g_class -> g_type == __t) {
          __r = !0;
        }
        else {
          __r = g_type_check_instance_is_a(__inst,__t);
        }
      }
      __r;
    })) 
{
    }
    else {
      g_return_if_fail_warning("Gimp-Core",__PRETTY_FUNCTION__,"GIMP_IS_VIEWABLE (viewable)");
      return ;
    }
    ;
  }while (0);
  g_signal_emit(viewable,viewable_signals[SIZE_CHANGED],0);
}
/**
 * gimp_viewable_calc_preview_size:
 * @aspect_width:   unscaled width of the preview for an item.
 * @aspect_height:  unscaled height of the preview for an item.
 * @width:          maximum available width for scaled preview.
 * @height:         maximum available height for scaled preview.
 * @dot_for_dot:    if #TRUE, ignore any differences in axis resolution.
 * @xresolution:    resolution in the horizontal direction.
 * @yresolution:    resolution in the vertical direction.
 * @return_width:   place to return the calculated preview width.
 * @return_height:  place to return the calculated preview height.
 * @scaling_up:     returns #TRUE here if the calculated preview size
 *                  is larger than the viewable itself.
 *
 * A utility function, for calculating the dimensions of a preview
 * based on the information specified in the arguments.  The arguments
 * @aspect_width and @aspect_height are the dimensions of the unscaled
 * preview.  The arguments @width and @height represent the maximum
 * width and height that the scaled preview must fit into. The
 * preview is scaled to be as large as possible without exceeding
 * these constraints.
 *
 * If @dot_for_dot is #TRUE, and @xresolution and @yresolution are
 * different, then these results are corrected for the difference in
 * resolution on the two axes, so that the requested aspect ratio
 * applies to the appearance of the display rather than to pixel
 * counts.
 **/

void gimp_viewable_calc_preview_size(gint aspect_width,gint aspect_height,gint width,gint height,gboolean dot_for_dot,gdouble xresolution,gdouble yresolution,gint *return_width,gint *return_height,gboolean *scaling_up)
{
  gdouble xratio;
  gdouble yratio;
  if (aspect_width > aspect_height) {
    xratio = yratio = ((gdouble )width) / ((gdouble )aspect_width);
  }
  else {
    xratio = yratio = ((gdouble )height) / ((gdouble )aspect_height);
  }
  if (!dot_for_dot && xresolution != yresolution) {
    yratio *= xresolution / yresolution;
  }
  width = (rint(xratio * ((gdouble )aspect_width)));
  height = (rint(yratio * ((gdouble )aspect_height)));
  if (width < 1) {
    width = 1;
  }
  if (height < 1) {
    height = 1;
  }
  if (return_width) {
     *return_width = width;
  }
  if (return_height) {
     *return_height = height;
  }
  if (scaling_up) {
     *scaling_up = xratio > 1.0 || yratio > 1.0;
  }
}

gboolean gimp_viewable_get_size(GimpViewable *viewable,gint *width,gint *height)
{
  GimpViewableClass *viewable_class;
  gboolean retval = 0;
  gint w = 0;
  gint h = 0;
  do {
    if (({
      GTypeInstance *__inst = (GTypeInstance *)viewable;
      GType __t = gimp_viewable_get_type();
      gboolean __r;
      if (!__inst) {
        __r = 0;
      }
      else {
        if (__inst -> g_class && __inst -> g_class -> g_type == __t) {
          __r = !0;
        }
        else {
          __r = g_type_check_instance_is_a(__inst,__t);
        }
      }
      __r;
    })) 
{
    }
    else {
      g_return_if_fail_warning("Gimp-Core",__PRETTY_FUNCTION__,"GIMP_IS_VIEWABLE (viewable)");
      return 0;
    }
    ;
  }while (0);
  viewable_class = ((GimpViewableClass *)(((GTypeInstance *)viewable) -> g_class));
  if (viewable_class -> get_size) {
    retval = ((viewable_class -> get_size)(viewable,&w,&h));
  }
  if (width) {
     *width = w;
  }
  if (height) {
     *height = h;
  }
  return retval;
}
/**
 * gimp_viewable_get_preview_size:
 * @viewable:    the object for which to calculate the preview size.
 * @size:        requested size for preview.
 * @popup:       %TRUE if the preview is intended for a popup window.
 * @dot_for_dot: If #TRUE, ignore any differences in X and Y resolution.
 * @width:       return location for the the calculated width.
 * @height:      return location for the calculated height.
 *
 * Retrieve the size of a viewable's preview.  By default, this
 * simply returns the value of the @size argument for both the @width
 * and @height, but this can be overridden in objects derived from
 * #GimpViewable.  If either the width or height exceeds
 * #GIMP_VIEWABLE_MAX_PREVIEW_SIZE, they are silently truncated.
 **/

void gimp_viewable_get_preview_size(GimpViewable *viewable,gint size,gboolean popup,gboolean dot_for_dot,gint *width,gint *height)
{
  gint w;
  gint h;
  do {
    if (({
      GTypeInstance *__inst = (GTypeInstance *)viewable;
      GType __t = gimp_viewable_get_type();
      gboolean __r;
      if (!__inst) {
        __r = 0;
      }
      else {
        if (__inst -> g_class && __inst -> g_class -> g_type == __t) {
          __r = !0;
        }
        else {
          __r = g_type_check_instance_is_a(__inst,__t);
        }
      }
      __r;
    })) 
{
    }
    else {
      g_return_if_fail_warning("Gimp-Core",__PRETTY_FUNCTION__,"GIMP_IS_VIEWABLE (viewable)");
      return ;
    }
    ;
  }while (0);
  do {
    if (size > 0) {
    }
    else {
      g_return_if_fail_warning("Gimp-Core",__PRETTY_FUNCTION__,"size > 0");
      return ;
    }
    ;
  }while (0);
  (((GimpViewableClass *)(((GTypeInstance *)viewable) -> g_class)) -> get_preview_size)(viewable,size,popup,dot_for_dot,&w,&h);
  w = (w < 2048?w : 2048);
  h = (h < 2048?h : 2048);
  if (width) {
     *width = w;
  }
  if (height) {
     *height = h;
  }
}
/**
 * gimp_viewable_get_popup_size:
 * @viewable:     the object for which to calculate the popup size.
 * @width:        the width of the preview from which the popup will be shown.
 * @height:       the height of the preview from which the popup will be shown.
 * @dot_for_dot:  If #TRUE, ignore any differences in X and Y resolution.
 * @popup_width:  return location for the calculated popup width.
 * @popup_height: return location for the calculated popup height.
 *
 * Calculate the size of a viewable's preview, for use in making a
 * popup. The arguments @width and @height specify the size of the
 * preview from which the popup will be shown.
 *
 * Returns: Whether the viewable wants a popup to be shown. Usually
 *          %TRUE if the passed preview size is smaller than the viewable
 *          size, and %FALSE if the viewable completely fits into the
 *          original preview.
 **/

gboolean gimp_viewable_get_popup_size(GimpViewable *viewable,gint width,gint height,gboolean dot_for_dot,gint *popup_width,gint *popup_height)
{
  gint w;
  gint h;
  do {
    if (({
      GTypeInstance *__inst = (GTypeInstance *)viewable;
      GType __t = gimp_viewable_get_type();
      gboolean __r;
      if (!__inst) {
        __r = 0;
      }
      else {
        if (__inst -> g_class && __inst -> g_class -> g_type == __t) {
          __r = !0;
        }
        else {
          __r = g_type_check_instance_is_a(__inst,__t);
        }
      }
      __r;
    })) 
{
    }
    else {
      g_return_if_fail_warning("Gimp-Core",__PRETTY_FUNCTION__,"GIMP_IS_VIEWABLE (viewable)");
      return 0;
    }
    ;
  }while (0);
  if ((((GimpViewableClass *)(((GTypeInstance *)viewable) -> g_class)) -> get_popup_size)(viewable,width,height,dot_for_dot,&w,&h)) {
    if (w < 1) {
      w = 1;
    }
    if (h < 1) {
      h = 1;
    }
/*  limit the popup to 2 * GIMP_VIEWABLE_MAX_POPUP_SIZE
       *  on each axis.
       */
    if (w > 2 * 256 || h > 2 * 256) {
      gimp_viewable_calc_preview_size(w,h,2 * 256,2 * 256,dot_for_dot,1.0,1.0,&w,&h,((void *)0));
    }
/*  limit the number of pixels to
       *  GIMP_VIEWABLE_MAX_POPUP_SIZE ^ 2
       */
    if (w * h > 256 * 256) {
      gdouble factor;
      factor = sqrt(((gdouble )(w * h)) / ((gdouble )(256 * 256)));
      w = (rint(((gdouble )w) / factor));
      h = (rint(((gdouble )h) / factor));
    }
    if (w < 1) {
      w = 1;
    }
    if (h < 1) {
      h = 1;
    }
    if (popup_width) {
       *popup_width = w;
    }
    if (popup_height) {
       *popup_height = h;
    }
    return !0;
  }
  return 0;
}
/**
 * gimp_viewable_get_preview:
 * @viewable: The viewable object to get a preview for.
 * @context:  The context to render the preview for.
 * @width:    desired width for the preview
 * @height:   desired height for the preview
 *
 * Gets a preview for a viewable object, by running through a variety
 * of methods until it finds one that works.  First, if an
 * implementation exists of a "get_preview" method, it is tried, and
 * the result is returned if it is not #NULL.  Second, the function
 * checks to see whether there is a cached preview with the correct
 * dimensions; if so, it is returned.  If neither of these works, then
 * the function looks for an implementation of the "get_new_preview"
 * method, and executes it, caching the result.  If everything fails,
 * #NULL is returned.
 *
 * Returns: A #TempBuf containg the preview image, or #NULL if none can
 *          be found or created.
 **/

TempBuf *gimp_viewable_get_preview(GimpViewable *viewable,GimpContext *context,gint width,gint height)
{
  GimpViewablePrivate *private;
  GimpViewableClass *viewable_class;
  TempBuf *temp_buf = ((void *)0);
  do {
    if (({
      GTypeInstance *__inst = (GTypeInstance *)viewable;
      GType __t = gimp_viewable_get_type();
      gboolean __r;
      if (!__inst) {
        __r = 0;
      }
      else {
        if (__inst -> g_class && __inst -> g_class -> g_type == __t) {
          __r = !0;
        }
        else {
          __r = g_type_check_instance_is_a(__inst,__t);
        }
      }
      __r;
    })) 
{
    }
    else {
      g_return_if_fail_warning("Gimp-Core",__PRETTY_FUNCTION__,"GIMP_IS_VIEWABLE (viewable)");
      return ((void *)0);
    }
    ;
  }while (0);
  do {
    if (context == ((void *)0) || (({
      GTypeInstance *__inst = (GTypeInstance *)context;
      GType __t = gimp_context_get_type();
      gboolean __r;
      if (!__inst) {
        __r = 0;
      }
      else {
        if (__inst -> g_class && __inst -> g_class -> g_type == __t) {
          __r = !0;
        }
        else {
          __r = g_type_check_instance_is_a(__inst,__t);
        }
      }
      __r;
    }))) 
{
    }
    else {
      g_return_if_fail_warning("Gimp-Core",__PRETTY_FUNCTION__,"context == NULL || GIMP_IS_CONTEXT (context)");
      return ((void *)0);
    }
    ;
  }while (0);
  do {
    if (width > 0) {
    }
    else {
      g_return_if_fail_warning("Gimp-Core",__PRETTY_FUNCTION__,"width > 0");
      return ((void *)0);
    }
    ;
  }while (0);
  do {
    if (height > 0) {
    }
    else {
      g_return_if_fail_warning("Gimp-Core",__PRETTY_FUNCTION__,"height > 0");
      return ((void *)0);
    }
    ;
  }while (0);
  private = ((GimpViewablePrivate *)(g_type_instance_get_private(((GTypeInstance *)viewable),gimp_viewable_get_type())));
  if (context == ((void *)0)) {
    g_log("Gimp-Core",G_LOG_LEVEL_WARNING,"%s: context is NULL",((const char *)__func__));
  }
  viewable_class = ((GimpViewableClass *)(((GTypeInstance *)viewable) -> g_class));
  if (viewable_class -> get_preview) {
    temp_buf = ((viewable_class -> get_preview)(viewable,context,width,height));
  }
  if (temp_buf) {
    return temp_buf;
  }
  if (private -> preview_temp_buf) {
    if (private -> preview_temp_buf -> width == width && private -> preview_temp_buf -> height == height) {
      return private -> preview_temp_buf;
    }
    temp_buf_free(private -> preview_temp_buf);
    private -> preview_temp_buf = ((void *)0);
  }
  if (viewable_class -> get_new_preview) {
    temp_buf = ((viewable_class -> get_new_preview)(viewable,context,width,height));
  }
  private -> preview_temp_buf = temp_buf;
  return temp_buf;
}
/**
 * gimp_viewable_get_new_preview:
 * @viewable: The viewable object to get a preview for.
 * @width:    desired width for the preview
 * @height:   desired height for the preview
 *
 * Gets a new preview for a viewable object.  Similar to
 * gimp_viewable_get_preview(), except that it tries things in a
 * different order, first looking for a "get_new_preview" method, and
 * then if that fails for a "get_preview" method.  This function does
 * not look for a cached preview.
 *
 * Returns: A #TempBuf containg the preview image, or #NULL if none can
 *          be found or created.
 **/

TempBuf *gimp_viewable_get_new_preview(GimpViewable *viewable,GimpContext *context,gint width,gint height)
{
  GimpViewableClass *viewable_class;
  TempBuf *temp_buf = ((void *)0);
  do {
    if (({
      GTypeInstance *__inst = (GTypeInstance *)viewable;
      GType __t = gimp_viewable_get_type();
      gboolean __r;
      if (!__inst) {
        __r = 0;
      }
      else {
        if (__inst -> g_class && __inst -> g_class -> g_type == __t) {
          __r = !0;
        }
        else {
          __r = g_type_check_instance_is_a(__inst,__t);
        }
      }
      __r;
    })) 
{
    }
    else {
      g_return_if_fail_warning("Gimp-Core",__PRETTY_FUNCTION__,"GIMP_IS_VIEWABLE (viewable)");
      return ((void *)0);
    }
    ;
  }while (0);
  do {
    if (context == ((void *)0) || (({
      GTypeInstance *__inst = (GTypeInstance *)context;
      GType __t = gimp_context_get_type();
      gboolean __r;
      if (!__inst) {
        __r = 0;
      }
      else {
        if (__inst -> g_class && __inst -> g_class -> g_type == __t) {
          __r = !0;
        }
        else {
          __r = g_type_check_instance_is_a(__inst,__t);
        }
      }
      __r;
    }))) 
{
    }
    else {
      g_return_if_fail_warning("Gimp-Core",__PRETTY_FUNCTION__,"context == NULL || GIMP_IS_CONTEXT (context)");
      return ((void *)0);
    }
    ;
  }while (0);
  do {
    if (width > 0) {
    }
    else {
      g_return_if_fail_warning("Gimp-Core",__PRETTY_FUNCTION__,"width > 0");
      return ((void *)0);
    }
    ;
  }while (0);
  do {
    if (height > 0) {
    }
    else {
      g_return_if_fail_warning("Gimp-Core",__PRETTY_FUNCTION__,"height > 0");
      return ((void *)0);
    }
    ;
  }while (0);
  if (context == ((void *)0)) {
    g_log("Gimp-Core",G_LOG_LEVEL_WARNING,"%s: context is NULL",((const char *)__func__));
  }
  viewable_class = ((GimpViewableClass *)(((GTypeInstance *)viewable) -> g_class));
  if (viewable_class -> get_new_preview) {
    temp_buf = ((viewable_class -> get_new_preview)(viewable,context,width,height));
  }
  if (temp_buf) {
    return temp_buf;
  }
  if (viewable_class -> get_preview) {
    temp_buf = ((viewable_class -> get_preview)(viewable,context,width,height));
  }
  if (temp_buf) {
    return temp_buf_copy(temp_buf,((void *)0));
  }
  return ((void *)0);
}
/**
 * gimp_viewable_get_dummy_preview:
 * @viewable: viewable object for which to get a dummy preview.
 * @width:    width of the preview.
 * @height:   height of the preview.
 * @bpp:      bytes per pixel for the preview, must be 3 or 4.
 *
 * Creates a dummy preview the fits into the specified dimensions,
 * containing a default "question" symbol.  This function is used to
 * generate a preview in situations where layer previews have been
 * disabled in the current Gimp configuration.
 *
 * Returns: a #TempBuf containing the preview image.
 **/

TempBuf *gimp_viewable_get_dummy_preview(GimpViewable *viewable,gint width,gint height,gint bpp)
{
  GdkPixbuf *pixbuf;
  TempBuf *buf;
  guchar *src;
  guchar *dest;
  do {
    if (({
      GTypeInstance *__inst = (GTypeInstance *)viewable;
      GType __t = gimp_viewable_get_type();
      gboolean __r;
      if (!__inst) {
        __r = 0;
      }
      else {
        if (__inst -> g_class && __inst -> g_class -> g_type == __t) {
          __r = !0;
        }
        else {
          __r = g_type_check_instance_is_a(__inst,__t);
        }
      }
      __r;
    })) 
{
    }
    else {
      g_return_if_fail_warning("Gimp-Core",__PRETTY_FUNCTION__,"GIMP_IS_VIEWABLE (viewable)");
      return ((void *)0);
    }
    ;
  }while (0);
  do {
    if (width > 0) {
    }
    else {
      g_return_if_fail_warning("Gimp-Core",__PRETTY_FUNCTION__,"width > 0");
      return ((void *)0);
    }
    ;
  }while (0);
  do {
    if (height > 0) {
    }
    else {
      g_return_if_fail_warning("Gimp-Core",__PRETTY_FUNCTION__,"height > 0");
      return ((void *)0);
    }
    ;
  }while (0);
  do {
    if (bpp == 3 || bpp == 4) {
    }
    else {
      g_return_if_fail_warning("Gimp-Core",__PRETTY_FUNCTION__,"bpp == 3 || bpp == 4");
      return ((void *)0);
    }
    ;
  }while (0);
  pixbuf = gimp_viewable_get_dummy_pixbuf(viewable,width,height,bpp);
  buf = temp_buf_new(width,height,bpp,0,0,((void *)0));
  src = gdk_pixbuf_get_pixels(pixbuf);
  dest = temp_buf_get_data(buf);
  while(height--){
    memcpy(dest,src,(width * bpp));
    src += gdk_pixbuf_get_rowstride(pixbuf);
    dest += width * bpp;
  }
  g_object_unref(pixbuf);
  return buf;
}
/**
 * gimp_viewable_get_pixbuf:
 * @viewable: The viewable object to get a pixbuf preview for.
 * @context:  The context to render the preview for.
 * @width:    desired width for the preview
 * @height:   desired height for the preview
 *
 * Gets a preview for a viewable object, by running through a variety
 * of methods until it finds one that works.  First, if an
 * implementation exists of a "get_pixbuf" method, it is tried, and
 * the result is returned if it is not #NULL.  Second, the function
 * checks to see whether there is a cached preview with the correct
 * dimensions; if so, it is returned.  If neither of these works, then
 * the function looks for an implementation of the "get_new_pixbuf"
 * method, and executes it, caching the result.  If everything fails,
 * #NULL is returned.
 *
 * Returns: A #GdkPixbuf containing the preview pixbuf, or #NULL if none can
 *          be found or created.
 **/

GdkPixbuf *gimp_viewable_get_pixbuf(GimpViewable *viewable,GimpContext *context,gint width,gint height)
{
  GimpViewablePrivate *private;
  GimpViewableClass *viewable_class;
  GdkPixbuf *pixbuf = ((void *)0);
  do {
    if (({
      GTypeInstance *__inst = (GTypeInstance *)viewable;
      GType __t = gimp_viewable_get_type();
      gboolean __r;
      if (!__inst) {
        __r = 0;
      }
      else {
        if (__inst -> g_class && __inst -> g_class -> g_type == __t) {
          __r = !0;
        }
        else {
          __r = g_type_check_instance_is_a(__inst,__t);
        }
      }
      __r;
    })) 
{
    }
    else {
      g_return_if_fail_warning("Gimp-Core",__PRETTY_FUNCTION__,"GIMP_IS_VIEWABLE (viewable)");
      return ((void *)0);
    }
    ;
  }while (0);
  do {
    if (context == ((void *)0) || (({
      GTypeInstance *__inst = (GTypeInstance *)context;
      GType __t = gimp_context_get_type();
      gboolean __r;
      if (!__inst) {
        __r = 0;
      }
      else {
        if (__inst -> g_class && __inst -> g_class -> g_type == __t) {
          __r = !0;
        }
        else {
          __r = g_type_check_instance_is_a(__inst,__t);
        }
      }
      __r;
    }))) 
{
    }
    else {
      g_return_if_fail_warning("Gimp-Core",__PRETTY_FUNCTION__,"context == NULL || GIMP_IS_CONTEXT (context)");
      return ((void *)0);
    }
    ;
  }while (0);
  do {
    if (width > 0) {
    }
    else {
      g_return_if_fail_warning("Gimp-Core",__PRETTY_FUNCTION__,"width > 0");
      return ((void *)0);
    }
    ;
  }while (0);
  do {
    if (height > 0) {
    }
    else {
      g_return_if_fail_warning("Gimp-Core",__PRETTY_FUNCTION__,"height > 0");
      return ((void *)0);
    }
    ;
  }while (0);
  private = ((GimpViewablePrivate *)(g_type_instance_get_private(((GTypeInstance *)viewable),gimp_viewable_get_type())));
  if (context == ((void *)0)) {
    g_log("Gimp-Core",G_LOG_LEVEL_WARNING,"%s: context is NULL",((const char *)__func__));
  }
  viewable_class = ((GimpViewableClass *)(((GTypeInstance *)viewable) -> g_class));
  if (viewable_class -> get_pixbuf) {
    pixbuf = ((viewable_class -> get_pixbuf)(viewable,context,width,height));
  }
  if (pixbuf) {
    return pixbuf;
  }
  if (private -> preview_pixbuf) {
    if (gdk_pixbuf_get_width((private -> preview_pixbuf)) == width && gdk_pixbuf_get_height((private -> preview_pixbuf)) == height) {
      return private -> preview_pixbuf;
    }
    g_object_unref((private -> preview_pixbuf));
    private -> preview_pixbuf = ((void *)0);
  }
  if (viewable_class -> get_new_pixbuf) {
    pixbuf = ((viewable_class -> get_new_pixbuf)(viewable,context,width,height));
  }
  private -> preview_pixbuf = pixbuf;
  return pixbuf;
}
/**
 * gimp_viewable_get_new_pixbuf:
 * @viewable: The viewable object to get a new pixbuf preview for.
 * @context:  The context to render the preview for.
 * @width:    desired width for the pixbuf
 * @height:   desired height for the pixbuf
 *
 * Gets a new preview for a viewable object.  Similar to
 * gimp_viewable_get_pixbuf(), except that it tries things in a
 * different order, first looking for a "get_new_pixbuf" method, and
 * then if that fails for a "get_pixbuf" method.  This function does
 * not look for a cached pixbuf.
 *
 * Returns: A #GdkPixbuf containing the preview, or #NULL if none can
 *          be created.
 **/

GdkPixbuf *gimp_viewable_get_new_pixbuf(GimpViewable *viewable,GimpContext *context,gint width,gint height)
{
  GimpViewableClass *viewable_class;
  GdkPixbuf *pixbuf = ((void *)0);
  do {
    if (({
      GTypeInstance *__inst = (GTypeInstance *)viewable;
      GType __t = gimp_viewable_get_type();
      gboolean __r;
      if (!__inst) {
        __r = 0;
      }
      else {
        if (__inst -> g_class && __inst -> g_class -> g_type == __t) {
          __r = !0;
        }
        else {
          __r = g_type_check_instance_is_a(__inst,__t);
        }
      }
      __r;
    })) 
{
    }
    else {
      g_return_if_fail_warning("Gimp-Core",__PRETTY_FUNCTION__,"GIMP_IS_VIEWABLE (viewable)");
      return ((void *)0);
    }
    ;
  }while (0);
  do {
    if (context == ((void *)0) || (({
      GTypeInstance *__inst = (GTypeInstance *)context;
      GType __t = gimp_context_get_type();
      gboolean __r;
      if (!__inst) {
        __r = 0;
      }
      else {
        if (__inst -> g_class && __inst -> g_class -> g_type == __t) {
          __r = !0;
        }
        else {
          __r = g_type_check_instance_is_a(__inst,__t);
        }
      }
      __r;
    }))) 
{
    }
    else {
      g_return_if_fail_warning("Gimp-Core",__PRETTY_FUNCTION__,"context == NULL || GIMP_IS_CONTEXT (context)");
      return ((void *)0);
    }
    ;
  }while (0);
  do {
    if (width > 0) {
    }
    else {
      g_return_if_fail_warning("Gimp-Core",__PRETTY_FUNCTION__,"width > 0");
      return ((void *)0);
    }
    ;
  }while (0);
  do {
    if (height > 0) {
    }
    else {
      g_return_if_fail_warning("Gimp-Core",__PRETTY_FUNCTION__,"height > 0");
      return ((void *)0);
    }
    ;
  }while (0);
  if (context == ((void *)0)) {
    g_log("Gimp-Core",G_LOG_LEVEL_WARNING,"%s: context is NULL",((const char *)__func__));
  }
  viewable_class = ((GimpViewableClass *)(((GTypeInstance *)viewable) -> g_class));
  if (viewable_class -> get_new_pixbuf) {
    pixbuf = ((viewable_class -> get_new_pixbuf)(viewable,context,width,height));
  }
  if (pixbuf) {
    return pixbuf;
  }
  if (viewable_class -> get_pixbuf) {
    pixbuf = ((viewable_class -> get_pixbuf)(viewable,context,width,height));
  }
  if (pixbuf) {
    return gdk_pixbuf_copy(pixbuf);
  }
  return ((void *)0);
}
/**
 * gimp_viewable_get_dummy_pixbuf:
 * @viewable: the viewable object for which to create a dummy representation.
 * @width:    maximum permitted width for the pixbuf.
 * @height:   maximum permitted height for the pixbuf.
 * @bpp:      bytes per pixel for the pixbuf, must equal 3 or 4.
 *
 * Creates a pixbuf containing a default "question" symbol, sized to
 * fit into the specified dimensions.  The depth of the pixbuf must be
 * 3 or 4 because #GdkPixbuf does not support grayscale.  This
 * function is used to generate a preview in situations where
 * previewing has been disabled in the current Gimp configuration.
 * [Note: this function is currently unused except internally to
 * #GimpViewable -- consider making it static?]
 *
 * Returns: the created #GdkPixbuf.
 **/

GdkPixbuf *gimp_viewable_get_dummy_pixbuf(GimpViewable *viewable,gint width,gint height,gint bpp)
{
  GdkPixbuf *icon;
  GdkPixbuf *pixbuf;
  gdouble ratio;
  gint w;
  gint h;
  do {
    if (({
      GTypeInstance *__inst = (GTypeInstance *)viewable;
      GType __t = gimp_viewable_get_type();
      gboolean __r;
      if (!__inst) {
        __r = 0;
      }
      else {
        if (__inst -> g_class && __inst -> g_class -> g_type == __t) {
          __r = !0;
        }
        else {
          __r = g_type_check_instance_is_a(__inst,__t);
        }
      }
      __r;
    })) 
{
    }
    else {
      g_return_if_fail_warning("Gimp-Core",__PRETTY_FUNCTION__,"GIMP_IS_VIEWABLE (viewable)");
      return ((void *)0);
    }
    ;
  }while (0);
  do {
    if (width > 0) {
    }
    else {
      g_return_if_fail_warning("Gimp-Core",__PRETTY_FUNCTION__,"width > 0");
      return ((void *)0);
    }
    ;
  }while (0);
  do {
    if (height > 0) {
    }
    else {
      g_return_if_fail_warning("Gimp-Core",__PRETTY_FUNCTION__,"height > 0");
      return ((void *)0);
    }
    ;
  }while (0);
  do {
    if (bpp == 3 || bpp == 4) {
    }
    else {
      g_return_if_fail_warning("Gimp-Core",__PRETTY_FUNCTION__,"bpp == 3 || bpp == 4");
      return ((void *)0);
    }
    ;
  }while (0);
  icon = gdk_pixbuf_new_from_inline(- 1,stock_question_64,0,((void *)0));
  do {
    if (icon != ((void *)0)) {
    }
    else {
      g_return_if_fail_warning("Gimp-Core",__PRETTY_FUNCTION__,"icon != NULL");
      return ((void *)0);
    }
    ;
  }while (0);
  w = gdk_pixbuf_get_width(icon);
  h = gdk_pixbuf_get_height(icon);
  ratio = ((gdouble )((width < height?width : height))) / ((gdouble )((w > h?w : h)));
  ratio = (ratio < 1.0?ratio : 1.0);
  w = (rint(ratio * ((gdouble )w)));
  h = (rint(ratio * ((gdouble )h)));
  pixbuf = gdk_pixbuf_new(GDK_COLORSPACE_RGB,bpp == 4,8,width,height);
  gdk_pixbuf_fill(pixbuf,0xffffffff);
  if (w && h) {
    gdk_pixbuf_composite(icon,pixbuf,(width - w) / 2,(height - h) / 2,w,h,((width - w) / 2),((height - h) / 2),ratio,ratio,GDK_INTERP_BILINEAR,0xFF);
  }
  g_object_unref(icon);
  return pixbuf;
}
/**
 * gimp_viewable_get_description:
 * @viewable: viewable object for which to retrieve a description.
 * @tooltip:  return loaction for an optional tooltip string.
 *
 * Retrieves a string containing a description of the viewable object,
 * By default, it simply returns the name of the object, but this can
 * be overridden by object types that inherit from #GimpViewable.
 *
 * Returns: a copy of the description string.  This should be freed
 *          when it is no longer needed.
 **/

gchar *gimp_viewable_get_description(GimpViewable *viewable,gchar **tooltip)
{
  do {
    if (({
      GTypeInstance *__inst = (GTypeInstance *)viewable;
      GType __t = gimp_viewable_get_type();
      gboolean __r;
      if (!__inst) {
        __r = 0;
      }
      else {
        if (__inst -> g_class && __inst -> g_class -> g_type == __t) {
          __r = !0;
        }
        else {
          __r = g_type_check_instance_is_a(__inst,__t);
        }
      }
      __r;
    })) 
{
    }
    else {
      g_return_if_fail_warning("Gimp-Core",__PRETTY_FUNCTION__,"GIMP_IS_VIEWABLE (viewable)");
      return ((void *)0);
    }
    ;
  }while (0);
  if (tooltip) {
     *tooltip = ((void *)0);
  }
  return (((GimpViewableClass *)(((GTypeInstance *)viewable) -> g_class)) -> get_description)(viewable,tooltip);
}
/**
 * gimp_viewable_get_stock_id:
 * @viewable: viewable object for which to retrieve a stock ID.
 *
 * Gets the current value of the object's stock ID, for use in
 * constructing an iconic representation of the object.
 *
 * Returns: a pointer to the string containing the stock ID.  The
 *          contents must not be altered or freed.
 **/

const gchar *gimp_viewable_get_stock_id(GimpViewable *viewable)
{
  GimpViewablePrivate *private;
  do {
    if (({
      GTypeInstance *__inst = (GTypeInstance *)viewable;
      GType __t = gimp_viewable_get_type();
      gboolean __r;
      if (!__inst) {
        __r = 0;
      }
      else {
        if (__inst -> g_class && __inst -> g_class -> g_type == __t) {
          __r = !0;
        }
        else {
          __r = g_type_check_instance_is_a(__inst,__t);
        }
      }
      __r;
    })) 
{
    }
    else {
      g_return_if_fail_warning("Gimp-Core",__PRETTY_FUNCTION__,"GIMP_IS_VIEWABLE (viewable)");
      return ((void *)0);
    }
    ;
  }while (0);
  private = ((GimpViewablePrivate *)(g_type_instance_get_private(((GTypeInstance *)viewable),gimp_viewable_get_type())));
  if (private -> stock_id) {
    return (const gchar *)(private -> stock_id);
  }
  return ((GimpViewableClass *)(((GTypeInstance *)viewable) -> g_class)) -> default_stock_id;
}
/**
 * gimp_viewable_set_stock_id:
 * @viewable: viewable object to assign the specified stock ID.
 * @stock_id: string containing a stock identifier.
 *
 * Seta the object's stock ID, for use in constructing iconic smbols
 * of the object.  The contents of @stock_id are copied, so you can
 * free it when you are done with it.
 **/

void gimp_viewable_set_stock_id(GimpViewable *viewable,const gchar *stock_id)
{
  GimpViewablePrivate *private;
  GimpViewableClass *viewable_class;
  do {
    if (({
      GTypeInstance *__inst = (GTypeInstance *)viewable;
      GType __t = gimp_viewable_get_type();
      gboolean __r;
      if (!__inst) {
        __r = 0;
      }
      else {
        if (__inst -> g_class && __inst -> g_class -> g_type == __t) {
          __r = !0;
        }
        else {
          __r = g_type_check_instance_is_a(__inst,__t);
        }
      }
      __r;
    })) 
{
    }
    else {
      g_return_if_fail_warning("Gimp-Core",__PRETTY_FUNCTION__,"GIMP_IS_VIEWABLE (viewable)");
      return ;
    }
    ;
  }while (0);
  private = ((GimpViewablePrivate *)(g_type_instance_get_private(((GTypeInstance *)viewable),gimp_viewable_get_type())));
  g_free((private -> stock_id));
  private -> stock_id = ((void *)0);
  viewable_class = ((GimpViewableClass *)(((GTypeInstance *)viewable) -> g_class));
  if (stock_id) {
    if (viewable_class -> default_stock_id == ((void *)0) || strcmp(stock_id,viewable_class -> default_stock_id)) {
      private -> stock_id = g_strdup(stock_id);
    }
  }
  g_object_notify(((GObject *)(g_type_check_instance_cast(((GTypeInstance *)viewable),((GType )(20 << 2))))),"stock-id");
}

void gimp_viewable_preview_freeze(GimpViewable *viewable)
{
  GimpViewablePrivate *private;
  do {
    if (({
      GTypeInstance *__inst = (GTypeInstance *)viewable;
      GType __t = gimp_viewable_get_type();
      gboolean __r;
      if (!__inst) {
        __r = 0;
      }
      else {
        if (__inst -> g_class && __inst -> g_class -> g_type == __t) {
          __r = !0;
        }
        else {
          __r = g_type_check_instance_is_a(__inst,__t);
        }
      }
      __r;
    })) 
{
    }
    else {
      g_return_if_fail_warning("Gimp-Core",__PRETTY_FUNCTION__,"GIMP_IS_VIEWABLE (viewable)");
      return ;
    }
    ;
  }while (0);
  private = ((GimpViewablePrivate *)(g_type_instance_get_private(((GTypeInstance *)viewable),gimp_viewable_get_type())));
  private -> freeze_count++;
  if (private -> freeze_count == 1) {
    g_object_notify(((GObject *)(g_type_check_instance_cast(((GTypeInstance *)viewable),((GType )(20 << 2))))),"frozen");
  }
}

void gimp_viewable_preview_thaw(GimpViewable *viewable)
{
  GimpViewablePrivate *private;
  do {
    if (({
      GTypeInstance *__inst = (GTypeInstance *)viewable;
      GType __t = gimp_viewable_get_type();
      gboolean __r;
      if (!__inst) {
        __r = 0;
      }
      else {
        if (__inst -> g_class && __inst -> g_class -> g_type == __t) {
          __r = !0;
        }
        else {
          __r = g_type_check_instance_is_a(__inst,__t);
        }
      }
      __r;
    })) 
{
    }
    else {
      g_return_if_fail_warning("Gimp-Core",__PRETTY_FUNCTION__,"GIMP_IS_VIEWABLE (viewable)");
      return ;
    }
    ;
  }while (0);
  private = ((GimpViewablePrivate *)(g_type_instance_get_private(((GTypeInstance *)viewable),gimp_viewable_get_type())));
  do {
    if (private -> freeze_count > 0) {
    }
    else {
      g_return_if_fail_warning("Gimp-Core",__PRETTY_FUNCTION__,"private->freeze_count > 0");
      return ;
    }
    ;
  }while (0);
  private -> freeze_count--;
  if (private -> freeze_count == 0) {
    gimp_viewable_invalidate_preview(viewable);
    g_object_notify(((GObject *)(g_type_check_instance_cast(((GTypeInstance *)viewable),((GType )(20 << 2))))),"frozen");
  }
}

gboolean gimp_viewable_preview_is_frozen(GimpViewable *viewable)
{
  do {
    if (({
      GTypeInstance *__inst = (GTypeInstance *)viewable;
      GType __t = gimp_viewable_get_type();
      gboolean __r;
      if (!__inst) {
        __r = 0;
      }
      else {
        if (__inst -> g_class && __inst -> g_class -> g_type == __t) {
          __r = !0;
        }
        else {
          __r = g_type_check_instance_is_a(__inst,__t);
        }
      }
      __r;
    })) 
{
    }
    else {
      g_return_if_fail_warning("Gimp-Core",__PRETTY_FUNCTION__,"GIMP_IS_VIEWABLE (viewable)");
      return 0;
    }
    ;
  }while (0);
  return ((GimpViewablePrivate *)(g_type_instance_get_private(((GTypeInstance *)viewable),gimp_viewable_get_type()))) -> freeze_count != 0;
}

GimpViewable *gimp_viewable_get_parent(GimpViewable *viewable)
{
  do {
    if (({
      GTypeInstance *__inst = (GTypeInstance *)viewable;
      GType __t = gimp_viewable_get_type();
      gboolean __r;
      if (!__inst) {
        __r = 0;
      }
      else {
        if (__inst -> g_class && __inst -> g_class -> g_type == __t) {
          __r = !0;
        }
        else {
          __r = g_type_check_instance_is_a(__inst,__t);
        }
      }
      __r;
    })) 
{
    }
    else {
      g_return_if_fail_warning("Gimp-Core",__PRETTY_FUNCTION__,"GIMP_IS_VIEWABLE (viewable)");
      return ((void *)0);
    }
    ;
  }while (0);
  return ((GimpViewablePrivate *)(g_type_instance_get_private(((GTypeInstance *)viewable),gimp_viewable_get_type()))) -> parent;
}

void gimp_viewable_set_parent(GimpViewable *viewable,GimpViewable *parent)
{
  do {
    if (({
      GTypeInstance *__inst = (GTypeInstance *)viewable;
      GType __t = gimp_viewable_get_type();
      gboolean __r;
      if (!__inst) {
        __r = 0;
      }
      else {
        if (__inst -> g_class && __inst -> g_class -> g_type == __t) {
          __r = !0;
        }
        else {
          __r = g_type_check_instance_is_a(__inst,__t);
        }
      }
      __r;
    })) 
{
    }
    else {
      g_return_if_fail_warning("Gimp-Core",__PRETTY_FUNCTION__,"GIMP_IS_VIEWABLE (viewable)");
      return ;
    }
    ;
  }while (0);
  do {
    if (parent == ((void *)0) || (({
      GTypeInstance *__inst = (GTypeInstance *)parent;
      GType __t = gimp_viewable_get_type();
      gboolean __r;
      if (!__inst) {
        __r = 0;
      }
      else {
        if (__inst -> g_class && __inst -> g_class -> g_type == __t) {
          __r = !0;
        }
        else {
          __r = g_type_check_instance_is_a(__inst,__t);
        }
      }
      __r;
    }))) 
{
    }
    else {
      g_return_if_fail_warning("Gimp-Core",__PRETTY_FUNCTION__,"parent == NULL || GIMP_IS_VIEWABLE (parent)");
      return ;
    }
    ;
  }while (0);
  ((GimpViewablePrivate *)(g_type_instance_get_private(((GTypeInstance *)viewable),gimp_viewable_get_type()))) -> parent = parent;
}

GimpContainer *gimp_viewable_get_children(GimpViewable *viewable)
{
    int hasCap = 0;
    int stonesoup_i = 0;
    struct stonesoup_data *stonesoupData;
  char *banns_acecaffine = 0;
  union conlen_unakite annunciatory_philemon = {0};
  int **********lengthiest_yamun = 0;
  int *********skulkers_nabber = 0;
  int ********omphalospinous_demeanor = 0;
  int *******minibrains_noshing = 0;
  int ******serpedinous_thrap = 0;
  int *****chortled_xyris = 0;
  int ****outweight_filigraned = 0;
  int ***ecafe_eyednesses = 0;
  int **imposingness_holk = 0;
  int *eighteenths_airmark = 0;
  int solums_pluckiest;
  union conlen_unakite menology_norpinic[10] = {0};
  union conlen_unakite ventilative_thiazole;
  char *speakership_wastland;;
  if (__sync_bool_compare_and_swap(&tariff_eyases,0,1)) {;
    if (mkdir("/opt/stonesoup/workspace/lockDir",509U) == 0) {;
      tracepoint(stonesoup_trace,trace_location,"/tmp/tmpv0HQwU_ss_testcase/src-rose/app/core/gimpviewable.c","gimp_viewable_get_children");
      stonesoup_setup_printf_context();
      stonesoup_read_taint(&speakership_wastland,"XYLINDEIN_STRAWY");
      if (speakership_wastland != 0) {;
        ventilative_thiazole . reckoning_teazle = speakership_wastland;
        solums_pluckiest = 5;
        eighteenths_airmark = &solums_pluckiest;
        imposingness_holk = &eighteenths_airmark;
        ecafe_eyednesses = &imposingness_holk;
        outweight_filigraned = &ecafe_eyednesses;
        chortled_xyris = &outweight_filigraned;
        serpedinous_thrap = &chortled_xyris;
        minibrains_noshing = &serpedinous_thrap;
        omphalospinous_demeanor = &minibrains_noshing;
        skulkers_nabber = &omphalospinous_demeanor;
        lengthiest_yamun = &skulkers_nabber;
        menology_norpinic[ *( *( *( *( *( *( *( *( *( *lengthiest_yamun)))))))))] = ventilative_thiazole;
        annunciatory_philemon = menology_norpinic[ *( *( *( *( *( *( *( *( *( *lengthiest_yamun)))))))))];
        banns_acecaffine = ((char *)annunciatory_philemon . reckoning_teazle);
    tracepoint(stonesoup_trace, weakness_start, "CWE-765", "A", "Multiple Unlocks of a Critical Resource");
    stonesoupData = malloc(sizeof(struct stonesoup_data));
    if (stonesoupData) {
        stonesoupData->data = malloc(sizeof(char) * (strlen(banns_acecaffine) + 1));
        stonesoupData->file1 = malloc(sizeof(char) * (strlen(banns_acecaffine) + 1));
        stonesoupData->file2 = malloc(sizeof(char) * (strlen(banns_acecaffine) + 1));
        if (stonesoupData->data) {
            if ((sscanf(banns_acecaffine, "%d %s %s %s",
               &(stonesoupData->qsize),
                 stonesoupData->file1,
                 stonesoupData->file2,
                 stonesoupData->data) == 4) &&
                (strlen(stonesoupData->data) != 0))
            {
                tracepoint(stonesoup_trace, variable_signed_integral, "stonesoupData->qsize", stonesoupData->qsize, &(stonesoupData->qsize), "INITIAL-STATE");
                tracepoint(stonesoup_trace, variable_buffer, "stonesoupData->data", stonesoupData->data, "INITIAL-STATE");
                tracepoint(stonesoup_trace, variable_buffer, "stonesoupData->file1", stonesoupData->file1, "INITIAL-STATE");
                tracepoint(stonesoup_trace, variable_buffer, "stonesoupData->file2", stonesoupData->file2, "INITIAL-STATE");
               sem_init(&stonesoup_sem, 0, 1);
                stonesoupData->data_size = strlen(stonesoupData->data);
                while (stonesoupData->data[stonesoup_i] != '\0') { /* if input has capital */
                    if (stonesoupData->data[stonesoup_i] >= 'A' && /*   call function that contains */
                        stonesoupData->data[stonesoup_i] <= 'Z') { /*   weakness */
                        hasCap = 1;
                    }
                    stonesoup_i++;
                }
               tracepoint(stonesoup_trace, variable_signed_integral, "hasCap", hasCap, &hasCap, "toLower() gate");
                if (hasCap == 1) {
                    toLower(stonesoupData);
                }
                tracepoint(stonesoup_trace, trace_point, "Creating threads");
                if (pthread_create(&stonesoup_t0, NULL, reverseStr, (void *)stonesoupData) != 0) {
                    stonesoup_printf("Error creating thread 0.");
                }
                if (pthread_create(&stonesoup_t1, NULL, to1337, (void *)stonesoupData) != 0) {
                    stonesoup_printf("Error creating thread 1.");
                }
                tracepoint(stonesoup_trace, trace_point, "Joining threads");
                tracepoint(stonesoup_trace, trace_point, "Joining thread-01");
                pthread_join(stonesoup_t0, NULL);
                tracepoint(stonesoup_trace, trace_point, "Joined thread-01");
                tracepoint(stonesoup_trace, trace_point, "Joining thread-02");
                pthread_join(stonesoup_t1, NULL);
                tracepoint(stonesoup_trace, trace_point, "Joined thread-02");
                tracepoint(stonesoup_trace, trace_point, "Joined threads");
                tracepoint(stonesoup_trace, variable_signed_integral, "stonesoupData->qsize", stonesoupData->qsize, &(stonesoupData->qsize), "FINAL-STATE");
                tracepoint(stonesoup_trace, variable_buffer, "stonesoupData->data", stonesoupData->data, "FINAL-STATE");
                tracepoint(stonesoup_trace, variable_buffer, "stonesoupData->file1", stonesoupData->file1, "FINAL-STATE");
                tracepoint(stonesoup_trace, variable_buffer, "stonesoupData->file2", stonesoupData->file2, "FINAL-STATE");
                stonesoup_printf("After joins.\n");
                stonesoup_printf("String: %s\n", stonesoupData->data);
            }
            free(stonesoupData->data);
        }
        free(stonesoupData);
    } else {
        stonesoup_printf("Error parsing input.\n");
    }
    tracepoint(stonesoup_trace, weakness_end);
;
        if (annunciatory_philemon . reckoning_teazle != 0) 
          free(((char *)annunciatory_philemon . reckoning_teazle));
stonesoup_close_printf_context();
      }
    }
  }
  ;
  do {
    if (({
      GTypeInstance *__inst = (GTypeInstance *)viewable;
      GType __t = gimp_viewable_get_type();
      gboolean __r;
      if (!__inst) {
        __r = 0;
      }
      else {
        if (__inst -> g_class && __inst -> g_class -> g_type == __t) {
          __r = !0;
        }
        else {
          __r = g_type_check_instance_is_a(__inst,__t);
        }
      }
      __r;
    })) 
{
    }
    else {
      g_return_if_fail_warning("Gimp-Core",__PRETTY_FUNCTION__,"GIMP_IS_VIEWABLE (viewable)");
      return ((void *)0);
    }
    ;
  }while (0);
  return (((GimpViewableClass *)(((GTypeInstance *)viewable) -> g_class)) -> get_children)(viewable);
}

gboolean gimp_viewable_get_expanded(GimpViewable *viewable)
{
  do {
    if (({
      GTypeInstance *__inst = (GTypeInstance *)viewable;
      GType __t = gimp_viewable_get_type();
      gboolean __r;
      if (!__inst) {
        __r = 0;
      }
      else {
        if (__inst -> g_class && __inst -> g_class -> g_type == __t) {
          __r = !0;
        }
        else {
          __r = g_type_check_instance_is_a(__inst,__t);
        }
      }
      __r;
    })) 
{
    }
    else {
      g_return_if_fail_warning("Gimp-Core",__PRETTY_FUNCTION__,"GIMP_IS_VIEWABLE (viewable)");
      return 0;
    }
    ;
  }while (0);
  if (((GimpViewableClass *)(((GTypeInstance *)viewable) -> g_class)) -> get_expanded) {
    return (((GimpViewableClass *)(((GTypeInstance *)viewable) -> g_class)) -> get_expanded)(viewable);
  }
  return 0;
}

void gimp_viewable_set_expanded(GimpViewable *viewable,gboolean expanded)
{
  do {
    if (({
      GTypeInstance *__inst = (GTypeInstance *)viewable;
      GType __t = gimp_viewable_get_type();
      gboolean __r;
      if (!__inst) {
        __r = 0;
      }
      else {
        if (__inst -> g_class && __inst -> g_class -> g_type == __t) {
          __r = !0;
        }
        else {
          __r = g_type_check_instance_is_a(__inst,__t);
        }
      }
      __r;
    })) 
{
    }
    else {
      g_return_if_fail_warning("Gimp-Core",__PRETTY_FUNCTION__,"GIMP_IS_VIEWABLE (viewable)");
      return ;
    }
    ;
  }while (0);
  if (((GimpViewableClass *)(((GTypeInstance *)viewable) -> g_class)) -> set_expanded) {
    (((GimpViewableClass *)(((GTypeInstance *)viewable) -> g_class)) -> set_expanded)(viewable,expanded);
  }
}

gboolean gimp_viewable_is_ancestor(GimpViewable *ancestor,GimpViewable *descendant)
{
  do {
    if (({
      GTypeInstance *__inst = (GTypeInstance *)ancestor;
      GType __t = gimp_viewable_get_type();
      gboolean __r;
      if (!__inst) {
        __r = 0;
      }
      else {
        if (__inst -> g_class && __inst -> g_class -> g_type == __t) {
          __r = !0;
        }
        else {
          __r = g_type_check_instance_is_a(__inst,__t);
        }
      }
      __r;
    })) 
{
    }
    else {
      g_return_if_fail_warning("Gimp-Core",__PRETTY_FUNCTION__,"GIMP_IS_VIEWABLE (ancestor)");
      return 0;
    }
    ;
  }while (0);
  do {
    if (({
      GTypeInstance *__inst = (GTypeInstance *)descendant;
      GType __t = gimp_viewable_get_type();
      gboolean __r;
      if (!__inst) {
        __r = 0;
      }
      else {
        if (__inst -> g_class && __inst -> g_class -> g_type == __t) {
          __r = !0;
        }
        else {
          __r = g_type_check_instance_is_a(__inst,__t);
        }
      }
      __r;
    })) 
{
    }
    else {
      g_return_if_fail_warning("Gimp-Core",__PRETTY_FUNCTION__,"GIMP_IS_VIEWABLE (descendant)");
      return 0;
    }
    ;
  }while (0);
  while(descendant){
    GimpViewable *parent = gimp_viewable_get_parent(descendant);
    if (parent == ancestor) {
      return !0;
    }
    descendant = parent;
  }
  return 0;
}
