#ifndef SERIALPORTREADER_GLOBAL_H
#define SERIALPORTREADER_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(SERIALPORTREADER_LIBRARY)
#  define SERIALPORTREADER_EXPORT Q_DECL_EXPORT
#else
#  define SERIALPORTREADER_EXPORT Q_DECL_IMPORT
#endif

#endif // SERIALPORTREADER_GLOBAL_H