/**
 * Autogenerated by Thrift Compiler (0.12.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef QueryService_H
#define QueryService_H

#include <thrift/TDispatchProcessor.h>
#include <thrift/async/TConcurrentClientSyncInfo.h>
#include "succinct_types.h"



#ifdef _MSC_VER
  #pragma warning( push )
  #pragma warning (disable : 4250 ) //inheriting methods via dominance 
#endif

class QueryServiceIf {
 public:
  virtual ~QueryServiceIf() {}
  virtual int32_t Initialize(const int32_t id) = 0;
  virtual void Regex(std::set<int64_t> & _return, const std::string& query) = 0;
  virtual void Extract(std::string& _return, const int64_t offset, const int64_t length) = 0;
  virtual int64_t Count(const std::string& query) = 0;
  virtual void Search(std::vector<int64_t> & _return, const std::string& query) = 0;
  virtual int64_t GetShardSize() = 0;
};

class QueryServiceIfFactory {
 public:
  typedef QueryServiceIf Handler;

  virtual ~QueryServiceIfFactory() {}

  virtual QueryServiceIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(QueryServiceIf* /* handler */) = 0;
};

class QueryServiceIfSingletonFactory : virtual public QueryServiceIfFactory {
 public:
  QueryServiceIfSingletonFactory(const ::apache::thrift::stdcxx::shared_ptr<QueryServiceIf>& iface) : iface_(iface) {}
  virtual ~QueryServiceIfSingletonFactory() {}

  virtual QueryServiceIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(QueryServiceIf* /* handler */) {}

 protected:
  ::apache::thrift::stdcxx::shared_ptr<QueryServiceIf> iface_;
};

class QueryServiceNull : virtual public QueryServiceIf {
 public:
  virtual ~QueryServiceNull() {}
  int32_t Initialize(const int32_t /* id */) {
    int32_t _return = 0;
    return _return;
  }
  void Regex(std::set<int64_t> & /* _return */, const std::string& /* query */) {
    return;
  }
  void Extract(std::string& /* _return */, const int64_t /* offset */, const int64_t /* length */) {
    return;
  }
  int64_t Count(const std::string& /* query */) {
    int64_t _return = 0;
    return _return;
  }
  void Search(std::vector<int64_t> & /* _return */, const std::string& /* query */) {
    return;
  }
  int64_t GetShardSize() {
    int64_t _return = 0;
    return _return;
  }
};

typedef struct _QueryService_Initialize_args__isset {
  _QueryService_Initialize_args__isset() : id(false) {}
  bool id :1;
} _QueryService_Initialize_args__isset;

class QueryService_Initialize_args {
 public:

  QueryService_Initialize_args(const QueryService_Initialize_args&);
  QueryService_Initialize_args& operator=(const QueryService_Initialize_args&);
  QueryService_Initialize_args() : id(0) {
  }

  virtual ~QueryService_Initialize_args() throw();
  int32_t id;

  _QueryService_Initialize_args__isset __isset;

  void __set_id(const int32_t val);

  bool operator == (const QueryService_Initialize_args & rhs) const
  {
    if (!(id == rhs.id))
      return false;
    return true;
  }
  bool operator != (const QueryService_Initialize_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const QueryService_Initialize_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class QueryService_Initialize_pargs {
 public:


  virtual ~QueryService_Initialize_pargs() throw();
  const int32_t* id;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _QueryService_Initialize_result__isset {
  _QueryService_Initialize_result__isset() : success(false) {}
  bool success :1;
} _QueryService_Initialize_result__isset;

class QueryService_Initialize_result {
 public:

  QueryService_Initialize_result(const QueryService_Initialize_result&);
  QueryService_Initialize_result& operator=(const QueryService_Initialize_result&);
  QueryService_Initialize_result() : success(0) {
  }

  virtual ~QueryService_Initialize_result() throw();
  int32_t success;

  _QueryService_Initialize_result__isset __isset;

  void __set_success(const int32_t val);

  bool operator == (const QueryService_Initialize_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const QueryService_Initialize_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const QueryService_Initialize_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _QueryService_Initialize_presult__isset {
  _QueryService_Initialize_presult__isset() : success(false) {}
  bool success :1;
} _QueryService_Initialize_presult__isset;

class QueryService_Initialize_presult {
 public:


  virtual ~QueryService_Initialize_presult() throw();
  int32_t* success;

  _QueryService_Initialize_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _QueryService_Regex_args__isset {
  _QueryService_Regex_args__isset() : query(false) {}
  bool query :1;
} _QueryService_Regex_args__isset;

class QueryService_Regex_args {
 public:

  QueryService_Regex_args(const QueryService_Regex_args&);
  QueryService_Regex_args& operator=(const QueryService_Regex_args&);
  QueryService_Regex_args() : query() {
  }

  virtual ~QueryService_Regex_args() throw();
  std::string query;

  _QueryService_Regex_args__isset __isset;

  void __set_query(const std::string& val);

  bool operator == (const QueryService_Regex_args & rhs) const
  {
    if (!(query == rhs.query))
      return false;
    return true;
  }
  bool operator != (const QueryService_Regex_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const QueryService_Regex_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class QueryService_Regex_pargs {
 public:


  virtual ~QueryService_Regex_pargs() throw();
  const std::string* query;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _QueryService_Regex_result__isset {
  _QueryService_Regex_result__isset() : success(false) {}
  bool success :1;
} _QueryService_Regex_result__isset;

class QueryService_Regex_result {
 public:

  QueryService_Regex_result(const QueryService_Regex_result&);
  QueryService_Regex_result& operator=(const QueryService_Regex_result&);
  QueryService_Regex_result() {
  }

  virtual ~QueryService_Regex_result() throw();
  std::set<int64_t>  success;

  _QueryService_Regex_result__isset __isset;

  void __set_success(const std::set<int64_t> & val);

  bool operator == (const QueryService_Regex_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const QueryService_Regex_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const QueryService_Regex_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _QueryService_Regex_presult__isset {
  _QueryService_Regex_presult__isset() : success(false) {}
  bool success :1;
} _QueryService_Regex_presult__isset;

class QueryService_Regex_presult {
 public:


  virtual ~QueryService_Regex_presult() throw();
  std::set<int64_t> * success;

  _QueryService_Regex_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _QueryService_Extract_args__isset {
  _QueryService_Extract_args__isset() : offset(false), length(false) {}
  bool offset :1;
  bool length :1;
} _QueryService_Extract_args__isset;

class QueryService_Extract_args {
 public:

  QueryService_Extract_args(const QueryService_Extract_args&);
  QueryService_Extract_args& operator=(const QueryService_Extract_args&);
  QueryService_Extract_args() : offset(0), length(0) {
  }

  virtual ~QueryService_Extract_args() throw();
  int64_t offset;
  int64_t length;

  _QueryService_Extract_args__isset __isset;

  void __set_offset(const int64_t val);

  void __set_length(const int64_t val);

  bool operator == (const QueryService_Extract_args & rhs) const
  {
    if (!(offset == rhs.offset))
      return false;
    if (!(length == rhs.length))
      return false;
    return true;
  }
  bool operator != (const QueryService_Extract_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const QueryService_Extract_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class QueryService_Extract_pargs {
 public:


  virtual ~QueryService_Extract_pargs() throw();
  const int64_t* offset;
  const int64_t* length;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _QueryService_Extract_result__isset {
  _QueryService_Extract_result__isset() : success(false) {}
  bool success :1;
} _QueryService_Extract_result__isset;

class QueryService_Extract_result {
 public:

  QueryService_Extract_result(const QueryService_Extract_result&);
  QueryService_Extract_result& operator=(const QueryService_Extract_result&);
  QueryService_Extract_result() : success() {
  }

  virtual ~QueryService_Extract_result() throw();
  std::string success;

  _QueryService_Extract_result__isset __isset;

  void __set_success(const std::string& val);

  bool operator == (const QueryService_Extract_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const QueryService_Extract_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const QueryService_Extract_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _QueryService_Extract_presult__isset {
  _QueryService_Extract_presult__isset() : success(false) {}
  bool success :1;
} _QueryService_Extract_presult__isset;

class QueryService_Extract_presult {
 public:


  virtual ~QueryService_Extract_presult() throw();
  std::string* success;

  _QueryService_Extract_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _QueryService_Count_args__isset {
  _QueryService_Count_args__isset() : query(false) {}
  bool query :1;
} _QueryService_Count_args__isset;

class QueryService_Count_args {
 public:

  QueryService_Count_args(const QueryService_Count_args&);
  QueryService_Count_args& operator=(const QueryService_Count_args&);
  QueryService_Count_args() : query() {
  }

  virtual ~QueryService_Count_args() throw();
  std::string query;

  _QueryService_Count_args__isset __isset;

  void __set_query(const std::string& val);

  bool operator == (const QueryService_Count_args & rhs) const
  {
    if (!(query == rhs.query))
      return false;
    return true;
  }
  bool operator != (const QueryService_Count_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const QueryService_Count_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class QueryService_Count_pargs {
 public:


  virtual ~QueryService_Count_pargs() throw();
  const std::string* query;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _QueryService_Count_result__isset {
  _QueryService_Count_result__isset() : success(false) {}
  bool success :1;
} _QueryService_Count_result__isset;

class QueryService_Count_result {
 public:

  QueryService_Count_result(const QueryService_Count_result&);
  QueryService_Count_result& operator=(const QueryService_Count_result&);
  QueryService_Count_result() : success(0) {
  }

  virtual ~QueryService_Count_result() throw();
  int64_t success;

  _QueryService_Count_result__isset __isset;

  void __set_success(const int64_t val);

  bool operator == (const QueryService_Count_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const QueryService_Count_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const QueryService_Count_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _QueryService_Count_presult__isset {
  _QueryService_Count_presult__isset() : success(false) {}
  bool success :1;
} _QueryService_Count_presult__isset;

class QueryService_Count_presult {
 public:


  virtual ~QueryService_Count_presult() throw();
  int64_t* success;

  _QueryService_Count_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _QueryService_Search_args__isset {
  _QueryService_Search_args__isset() : query(false) {}
  bool query :1;
} _QueryService_Search_args__isset;

class QueryService_Search_args {
 public:

  QueryService_Search_args(const QueryService_Search_args&);
  QueryService_Search_args& operator=(const QueryService_Search_args&);
  QueryService_Search_args() : query() {
  }

  virtual ~QueryService_Search_args() throw();
  std::string query;

  _QueryService_Search_args__isset __isset;

  void __set_query(const std::string& val);

  bool operator == (const QueryService_Search_args & rhs) const
  {
    if (!(query == rhs.query))
      return false;
    return true;
  }
  bool operator != (const QueryService_Search_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const QueryService_Search_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class QueryService_Search_pargs {
 public:


  virtual ~QueryService_Search_pargs() throw();
  const std::string* query;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _QueryService_Search_result__isset {
  _QueryService_Search_result__isset() : success(false) {}
  bool success :1;
} _QueryService_Search_result__isset;

class QueryService_Search_result {
 public:

  QueryService_Search_result(const QueryService_Search_result&);
  QueryService_Search_result& operator=(const QueryService_Search_result&);
  QueryService_Search_result() {
  }

  virtual ~QueryService_Search_result() throw();
  std::vector<int64_t>  success;

  _QueryService_Search_result__isset __isset;

  void __set_success(const std::vector<int64_t> & val);

  bool operator == (const QueryService_Search_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const QueryService_Search_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const QueryService_Search_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _QueryService_Search_presult__isset {
  _QueryService_Search_presult__isset() : success(false) {}
  bool success :1;
} _QueryService_Search_presult__isset;

class QueryService_Search_presult {
 public:


  virtual ~QueryService_Search_presult() throw();
  std::vector<int64_t> * success;

  _QueryService_Search_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class QueryService_GetShardSize_args {
 public:

  QueryService_GetShardSize_args(const QueryService_GetShardSize_args&);
  QueryService_GetShardSize_args& operator=(const QueryService_GetShardSize_args&);
  QueryService_GetShardSize_args() {
  }

  virtual ~QueryService_GetShardSize_args() throw();

  bool operator == (const QueryService_GetShardSize_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const QueryService_GetShardSize_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const QueryService_GetShardSize_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class QueryService_GetShardSize_pargs {
 public:


  virtual ~QueryService_GetShardSize_pargs() throw();

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _QueryService_GetShardSize_result__isset {
  _QueryService_GetShardSize_result__isset() : success(false) {}
  bool success :1;
} _QueryService_GetShardSize_result__isset;

class QueryService_GetShardSize_result {
 public:

  QueryService_GetShardSize_result(const QueryService_GetShardSize_result&);
  QueryService_GetShardSize_result& operator=(const QueryService_GetShardSize_result&);
  QueryService_GetShardSize_result() : success(0) {
  }

  virtual ~QueryService_GetShardSize_result() throw();
  int64_t success;

  _QueryService_GetShardSize_result__isset __isset;

  void __set_success(const int64_t val);

  bool operator == (const QueryService_GetShardSize_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const QueryService_GetShardSize_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const QueryService_GetShardSize_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _QueryService_GetShardSize_presult__isset {
  _QueryService_GetShardSize_presult__isset() : success(false) {}
  bool success :1;
} _QueryService_GetShardSize_presult__isset;

class QueryService_GetShardSize_presult {
 public:


  virtual ~QueryService_GetShardSize_presult() throw();
  int64_t* success;

  _QueryService_GetShardSize_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class QueryServiceClient : virtual public QueryServiceIf {
 public:
  QueryServiceClient(apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  QueryServiceClient(apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  int32_t Initialize(const int32_t id);
  void send_Initialize(const int32_t id);
  int32_t recv_Initialize();
  void Regex(std::set<int64_t> & _return, const std::string& query);
  void send_Regex(const std::string& query);
  void recv_Regex(std::set<int64_t> & _return);
  void Extract(std::string& _return, const int64_t offset, const int64_t length);
  void send_Extract(const int64_t offset, const int64_t length);
  void recv_Extract(std::string& _return);
  int64_t Count(const std::string& query);
  void send_Count(const std::string& query);
  int64_t recv_Count();
  void Search(std::vector<int64_t> & _return, const std::string& query);
  void send_Search(const std::string& query);
  void recv_Search(std::vector<int64_t> & _return);
  int64_t GetShardSize();
  void send_GetShardSize();
  int64_t recv_GetShardSize();
 protected:
  apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class QueryServiceProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  ::apache::thrift::stdcxx::shared_ptr<QueryServiceIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (QueryServiceProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_Initialize(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_Regex(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_Extract(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_Count(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_Search(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_GetShardSize(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  QueryServiceProcessor(::apache::thrift::stdcxx::shared_ptr<QueryServiceIf> iface) :
    iface_(iface) {
    processMap_["Initialize"] = &QueryServiceProcessor::process_Initialize;
    processMap_["Regex"] = &QueryServiceProcessor::process_Regex;
    processMap_["Extract"] = &QueryServiceProcessor::process_Extract;
    processMap_["Count"] = &QueryServiceProcessor::process_Count;
    processMap_["Search"] = &QueryServiceProcessor::process_Search;
    processMap_["GetShardSize"] = &QueryServiceProcessor::process_GetShardSize;
  }

  virtual ~QueryServiceProcessor() {}
};

class QueryServiceProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  QueryServiceProcessorFactory(const ::apache::thrift::stdcxx::shared_ptr< QueryServiceIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::apache::thrift::stdcxx::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::apache::thrift::stdcxx::shared_ptr< QueryServiceIfFactory > handlerFactory_;
};

class QueryServiceMultiface : virtual public QueryServiceIf {
 public:
  QueryServiceMultiface(std::vector<apache::thrift::stdcxx::shared_ptr<QueryServiceIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~QueryServiceMultiface() {}
 protected:
  std::vector<apache::thrift::stdcxx::shared_ptr<QueryServiceIf> > ifaces_;
  QueryServiceMultiface() {}
  void add(::apache::thrift::stdcxx::shared_ptr<QueryServiceIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  int32_t Initialize(const int32_t id) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->Initialize(id);
    }
    return ifaces_[i]->Initialize(id);
  }

  void Regex(std::set<int64_t> & _return, const std::string& query) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->Regex(_return, query);
    }
    ifaces_[i]->Regex(_return, query);
    return;
  }

  void Extract(std::string& _return, const int64_t offset, const int64_t length) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->Extract(_return, offset, length);
    }
    ifaces_[i]->Extract(_return, offset, length);
    return;
  }

  int64_t Count(const std::string& query) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->Count(query);
    }
    return ifaces_[i]->Count(query);
  }

  void Search(std::vector<int64_t> & _return, const std::string& query) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->Search(_return, query);
    }
    ifaces_[i]->Search(_return, query);
    return;
  }

  int64_t GetShardSize() {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->GetShardSize();
    }
    return ifaces_[i]->GetShardSize();
  }

};

// The 'concurrent' client is a thread safe client that correctly handles
// out of order responses.  It is slower than the regular client, so should
// only be used when you need to share a connection among multiple threads
class QueryServiceConcurrentClient : virtual public QueryServiceIf {
 public:
  QueryServiceConcurrentClient(apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  QueryServiceConcurrentClient(apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  int32_t Initialize(const int32_t id);
  int32_t send_Initialize(const int32_t id);
  int32_t recv_Initialize(const int32_t seqid);
  void Regex(std::set<int64_t> & _return, const std::string& query);
  int32_t send_Regex(const std::string& query);
  void recv_Regex(std::set<int64_t> & _return, const int32_t seqid);
  void Extract(std::string& _return, const int64_t offset, const int64_t length);
  int32_t send_Extract(const int64_t offset, const int64_t length);
  void recv_Extract(std::string& _return, const int32_t seqid);
  int64_t Count(const std::string& query);
  int32_t send_Count(const std::string& query);
  int64_t recv_Count(const int32_t seqid);
  void Search(std::vector<int64_t> & _return, const std::string& query);
  int32_t send_Search(const std::string& query);
  void recv_Search(std::vector<int64_t> & _return, const int32_t seqid);
  int64_t GetShardSize();
  int32_t send_GetShardSize();
  int64_t recv_GetShardSize(const int32_t seqid);
 protected:
  apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
  ::apache::thrift::async::TConcurrentClientSyncInfo sync_;
};

#ifdef _MSC_VER
  #pragma warning( pop )
#endif



#endif
