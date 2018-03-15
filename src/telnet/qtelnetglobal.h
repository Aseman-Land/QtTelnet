#ifndef QTELNETGLOBAL_H
#define QTELNETGLOBAL_H

#include <QtGlobal>

#if !defined(QT_STATIC) && !defined(TELNET_NO_LIB)
#  if defined(QT_BUILD_TELNET_LIB)
#    define Q_TELNET_EXPORT Q_DECL_EXPORT
#  else
#    define Q_TELNET_EXPORT Q_DECL_IMPORT
#  endif
#else
#  define Q_TELNET_EXPORT
#endif

#endif // QTELNETGLOBAL_H
