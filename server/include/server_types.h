/**
 * Autogenerated by Thrift Compiler (0.9.3)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef server_TYPES_H
#define server_TYPES_H

#include <iosfwd>

#include <thrift/Thrift.h>
#include <thrift/TApplicationException.h>
#include <thrift/protocol/TProtocol.h>
#include <thrift/transport/TTransport.h>

#include <thrift/cxxfunctional.h>




class ServerHeartBeat;

typedef struct _ServerHeartBeat__isset {
  _ServerHeartBeat__isset() : timestamp(false) {}
  bool timestamp :1;
} _ServerHeartBeat__isset;

class ServerHeartBeat {
 public:

  ServerHeartBeat(const ServerHeartBeat&);
  ServerHeartBeat& operator=(const ServerHeartBeat&);
  ServerHeartBeat() : timestamp(0) {
  }

  virtual ~ServerHeartBeat() throw();
  int64_t timestamp;

  _ServerHeartBeat__isset __isset;

  void __set_timestamp(const int64_t val);

  bool operator == (const ServerHeartBeat & rhs) const
  {
    if (!(timestamp == rhs.timestamp))
      return false;
    return true;
  }
  bool operator != (const ServerHeartBeat &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ServerHeartBeat & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(ServerHeartBeat &a, ServerHeartBeat &b);

inline std::ostream& operator<<(std::ostream& out, const ServerHeartBeat& obj)
{
  obj.printTo(out);
  return out;
}



#endif
