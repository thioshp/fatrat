#include "HttpResponse.h"
#include <cassert>

HttpResponse::HttpResponse(HttpDaemon *daemon, int id)
    : m_daemon(daemon), m_id(id), m_bHandled(false)
{
    addHeader("Server", "FatRat");
}

void HttpResponse::markHandled()
{
	assert(!m_bHandled);
	m_bHandled = true;
}

void HttpResponse::sendErrorGeneric(int code, const char *desc)
{
	markHandled();
    // TODO
}

void HttpResponse::sendResponseSimple(int code, const char *desc, const char *data, size_t len)
{
	markHandled();
    // TODO
}

void HttpResponse::sendResponseCallback(int code, const char* desc)
{
	markHandled();
    // TODO
}

void HttpResponse::sendResponseAsyncStart(int code, const char* desc)
{
	markHandled();
    // TODO: remove from PollIn notifications!
}

void HttpResponse::sendResponseAsyncData(const char* data, size_t len)
{

}

void HttpResponse::sendResponseAsyncEnd()
{
    // TODO: check sent length
    // TODO: mark as complete
	// TODO: process extra incoming bytes left in the buffer
}

void HttpResponse::addHeader(QString name, QString value)
{
    m_headers[name] = value;
}