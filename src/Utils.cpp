// ─────────────────────────────────────────────────────────────
//                  INCLUDE
// ─────────────────────────────────────────────────────────────

// Application Header
#include <Qaterial/Utils.hpp>
#include <Qaterial/Version.hpp>
#include <Qaterial/Logger.hpp>

// Qt Header
#include <QCoreApplication> // Call register type at startup when loaded as a dynamic library

// ─────────────────────────────────────────────────────────────
//                  DECLARATION
// ─────────────────────────────────────────────────────────────

#ifdef NDEBUG
# define LOG_DEV_DEBUG(str, ...) do {} while (0)
#else
# define LOG_DEV_DEBUG(str, ...) Qaterial::Logger::UTILS->debug( str, ## __VA_ARGS__ );
#endif

#ifdef NDEBUG
# define LOG_DEV_INFO(str, ...)  do {} while (0)
#else
# define LOG_DEV_INFO(str, ...)  Qaterial::Logger::UTILS->info(  str, ## __VA_ARGS__ );
#endif

#ifdef NDEBUG
# define LOG_DEV_WARN(str, ...)  do {} while (0)
#else
# define LOG_DEV_WARN(str, ...)  Qaterial::Logger::UTILS->warn(  str, ## __VA_ARGS__ );
#endif

#ifdef NDEBUG
# define LOG_DEV_ERR(str, ...)   do {} while (0)
#else
# define LOG_DEV_ERR(str, ...)   Qaterial::Logger::UTILS->error( str, ## __VA_ARGS__ );
#endif

#define LOG_DEBUG(str, ...)      Qaterial::Logger::UTILS->debug( str, ## __VA_ARGS__ );
#define LOG_INFO(str, ...)       Qaterial::Logger::UTILS->info(  str, ## __VA_ARGS__ );
#define LOG_WARN(str, ...)       Qaterial::Logger::UTILS->warn(  str, ## __VA_ARGS__ );
#define LOG_ERR(str, ...)        Qaterial::Logger::UTILS->error( str, ## __VA_ARGS__ );

// ─────────────────────────────────────────────────────────────
//                  FUNCTIONS
// ─────────────────────────────────────────────────────────────

static const char* _defaultUri = "Qaterial";
static const char** _uri = &_defaultUri;
static quint8 _major = 1;
static quint8 _minor = 0;

static void Qaterial_registerTypes()
{
    LOG_DEV_INFO("Register Qaterial v{}", Qaterial::Version::version().readable().toStdString());

    LOG_DEV_INFO("Register Singleton {}.Version {}.{} to QML", *_uri, _major, _minor);
    Qaterial::Version::registerSingleton(*_uri, _major, _minor);
}

static void Qaterial_registerTypes(const char* uri, const quint8 major, const quint8 minor)
{
    if(uri)
        _uri = &uri;
    _major = major;
    _minor = minor;
    Qaterial_registerTypes();
}

static void Qaterial_loadResources()
{
    LOG_DEV_INFO("Load Qaterial.qrc v{}", qPrintable(Qaterial::Version::version().readable()));
    Q_INIT_RESOURCE(Qaterial);
}

#ifndef QATERIAL_STATIC
Q_COREAPP_STARTUP_FUNCTION(Qaterial_registerTypes);
Q_COREAPP_STARTUP_FUNCTION(Qaterial_loadResources);
#endif

using namespace Qaterial;

void Utils::registerTypes(const char* uri, const quint8 major, const quint8 minor)
{
    ::Qaterial_registerTypes(uri, major, minor);
}

void Utils::loadResources()
{
    ::Qaterial_loadResources();
}
