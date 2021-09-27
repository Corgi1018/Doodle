// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: metadata_server.proto

#include "metadata_server.pb.h"
#include "metadata_server.grpc.pb.h"

#include <functional>
#include <grpcpp/impl/codegen/async_stream.h>
#include <grpcpp/impl/codegen/async_unary_call.h>
#include <grpcpp/impl/codegen/channel_interface.h>
#include <grpcpp/impl/codegen/client_unary_call.h>
#include <grpcpp/impl/codegen/client_callback.h>
#include <grpcpp/impl/codegen/message_allocator.h>
#include <grpcpp/impl/codegen/method_handler.h>
#include <grpcpp/impl/codegen/rpc_service_method.h>
#include <grpcpp/impl/codegen/server_callback.h>
#include <grpcpp/impl/codegen/server_callback_handlers.h>
#include <grpcpp/impl/codegen/server_context.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/sync_stream.h>
namespace doodle {

static const char* metadata_server_method_names[] = {
  "/doodle.metadata_server/install_metadata",
  "/doodle.metadata_server/delete_metadata",
  "/doodle.metadata_server/update_metadata",
  "/doodle.metadata_server/filter_metadata",
  "/doodle.metadata_server/install_user_date",
  "/doodle.metadata_server/update_user_date",
  "/doodle.metadata_server/delete_user_date",
  "/doodle.metadata_server/filter_user_date",
};

std::unique_ptr< metadata_server::Stub> metadata_server::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< metadata_server::Stub> stub(new metadata_server::Stub(channel));
  return stub;
}

metadata_server::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel)
  : channel_(channel), rpcmethod_install_metadata_(metadata_server_method_names[0], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_delete_metadata_(metadata_server_method_names[1], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_update_metadata_(metadata_server_method_names[2], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_filter_metadata_(metadata_server_method_names[3], ::grpc::internal::RpcMethod::SERVER_STREAMING, channel)
  , rpcmethod_install_user_date_(metadata_server_method_names[4], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_update_user_date_(metadata_server_method_names[5], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_delete_user_date_(metadata_server_method_names[6], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_filter_user_date_(metadata_server_method_names[7], ::grpc::internal::RpcMethod::SERVER_STREAMING, channel)
  {}

::grpc::Status metadata_server::Stub::install_metadata(::grpc::ClientContext* context, const ::doodle::metadata_database& request, ::doodle::metadata_database* response) {
  return ::grpc::internal::BlockingUnaryCall< ::doodle::metadata_database, ::doodle::metadata_database, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_install_metadata_, context, request, response);
}

void metadata_server::Stub::experimental_async::install_metadata(::grpc::ClientContext* context, const ::doodle::metadata_database* request, ::doodle::metadata_database* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::doodle::metadata_database, ::doodle::metadata_database, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_install_metadata_, context, request, response, std::move(f));
}

void metadata_server::Stub::experimental_async::install_metadata(::grpc::ClientContext* context, const ::doodle::metadata_database* request, ::doodle::metadata_database* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_install_metadata_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::doodle::metadata_database>* metadata_server::Stub::PrepareAsyncinstall_metadataRaw(::grpc::ClientContext* context, const ::doodle::metadata_database& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::doodle::metadata_database, ::doodle::metadata_database, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_install_metadata_, context, request);
}

::grpc::ClientAsyncResponseReader< ::doodle::metadata_database>* metadata_server::Stub::Asyncinstall_metadataRaw(::grpc::ClientContext* context, const ::doodle::metadata_database& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncinstall_metadataRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status metadata_server::Stub::delete_metadata(::grpc::ClientContext* context, const ::doodle::metadata_database& request, ::doodle::metadata_database* response) {
  return ::grpc::internal::BlockingUnaryCall< ::doodle::metadata_database, ::doodle::metadata_database, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_delete_metadata_, context, request, response);
}

void metadata_server::Stub::experimental_async::delete_metadata(::grpc::ClientContext* context, const ::doodle::metadata_database* request, ::doodle::metadata_database* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::doodle::metadata_database, ::doodle::metadata_database, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_delete_metadata_, context, request, response, std::move(f));
}

void metadata_server::Stub::experimental_async::delete_metadata(::grpc::ClientContext* context, const ::doodle::metadata_database* request, ::doodle::metadata_database* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_delete_metadata_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::doodle::metadata_database>* metadata_server::Stub::PrepareAsyncdelete_metadataRaw(::grpc::ClientContext* context, const ::doodle::metadata_database& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::doodle::metadata_database, ::doodle::metadata_database, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_delete_metadata_, context, request);
}

::grpc::ClientAsyncResponseReader< ::doodle::metadata_database>* metadata_server::Stub::Asyncdelete_metadataRaw(::grpc::ClientContext* context, const ::doodle::metadata_database& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncdelete_metadataRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status metadata_server::Stub::update_metadata(::grpc::ClientContext* context, const ::doodle::metadata_database& request, ::doodle::metadata_database* response) {
  return ::grpc::internal::BlockingUnaryCall< ::doodle::metadata_database, ::doodle::metadata_database, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_update_metadata_, context, request, response);
}

void metadata_server::Stub::experimental_async::update_metadata(::grpc::ClientContext* context, const ::doodle::metadata_database* request, ::doodle::metadata_database* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::doodle::metadata_database, ::doodle::metadata_database, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_update_metadata_, context, request, response, std::move(f));
}

void metadata_server::Stub::experimental_async::update_metadata(::grpc::ClientContext* context, const ::doodle::metadata_database* request, ::doodle::metadata_database* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_update_metadata_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::doodle::metadata_database>* metadata_server::Stub::PrepareAsyncupdate_metadataRaw(::grpc::ClientContext* context, const ::doodle::metadata_database& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::doodle::metadata_database, ::doodle::metadata_database, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_update_metadata_, context, request);
}

::grpc::ClientAsyncResponseReader< ::doodle::metadata_database>* metadata_server::Stub::Asyncupdate_metadataRaw(::grpc::ClientContext* context, const ::doodle::metadata_database& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncupdate_metadataRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::ClientReader< ::doodle::metadata_database>* metadata_server::Stub::filter_metadataRaw(::grpc::ClientContext* context, const ::doodle::metadata_database_filter& request) {
  return ::grpc::internal::ClientReaderFactory< ::doodle::metadata_database>::Create(channel_.get(), rpcmethod_filter_metadata_, context, request);
}

void metadata_server::Stub::experimental_async::filter_metadata(::grpc::ClientContext* context, const ::doodle::metadata_database_filter* request, ::grpc::experimental::ClientReadReactor< ::doodle::metadata_database>* reactor) {
  ::grpc::internal::ClientCallbackReaderFactory< ::doodle::metadata_database>::Create(stub_->channel_.get(), stub_->rpcmethod_filter_metadata_, context, request, reactor);
}

::grpc::ClientAsyncReader< ::doodle::metadata_database>* metadata_server::Stub::Asyncfilter_metadataRaw(::grpc::ClientContext* context, const ::doodle::metadata_database_filter& request, ::grpc::CompletionQueue* cq, void* tag) {
  return ::grpc::internal::ClientAsyncReaderFactory< ::doodle::metadata_database>::Create(channel_.get(), cq, rpcmethod_filter_metadata_, context, request, true, tag);
}

::grpc::ClientAsyncReader< ::doodle::metadata_database>* metadata_server::Stub::PrepareAsyncfilter_metadataRaw(::grpc::ClientContext* context, const ::doodle::metadata_database_filter& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncReaderFactory< ::doodle::metadata_database>::Create(channel_.get(), cq, rpcmethod_filter_metadata_, context, request, false, nullptr);
}

::grpc::Status metadata_server::Stub::install_user_date(::grpc::ClientContext* context, const ::doodle::user_database& request, ::doodle::user_database* response) {
  return ::grpc::internal::BlockingUnaryCall< ::doodle::user_database, ::doodle::user_database, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_install_user_date_, context, request, response);
}

void metadata_server::Stub::experimental_async::install_user_date(::grpc::ClientContext* context, const ::doodle::user_database* request, ::doodle::user_database* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::doodle::user_database, ::doodle::user_database, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_install_user_date_, context, request, response, std::move(f));
}

void metadata_server::Stub::experimental_async::install_user_date(::grpc::ClientContext* context, const ::doodle::user_database* request, ::doodle::user_database* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_install_user_date_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::doodle::user_database>* metadata_server::Stub::PrepareAsyncinstall_user_dateRaw(::grpc::ClientContext* context, const ::doodle::user_database& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::doodle::user_database, ::doodle::user_database, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_install_user_date_, context, request);
}

::grpc::ClientAsyncResponseReader< ::doodle::user_database>* metadata_server::Stub::Asyncinstall_user_dateRaw(::grpc::ClientContext* context, const ::doodle::user_database& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncinstall_user_dateRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status metadata_server::Stub::update_user_date(::grpc::ClientContext* context, const ::doodle::user_database& request, ::doodle::user_database* response) {
  return ::grpc::internal::BlockingUnaryCall< ::doodle::user_database, ::doodle::user_database, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_update_user_date_, context, request, response);
}

void metadata_server::Stub::experimental_async::update_user_date(::grpc::ClientContext* context, const ::doodle::user_database* request, ::doodle::user_database* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::doodle::user_database, ::doodle::user_database, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_update_user_date_, context, request, response, std::move(f));
}

void metadata_server::Stub::experimental_async::update_user_date(::grpc::ClientContext* context, const ::doodle::user_database* request, ::doodle::user_database* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_update_user_date_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::doodle::user_database>* metadata_server::Stub::PrepareAsyncupdate_user_dateRaw(::grpc::ClientContext* context, const ::doodle::user_database& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::doodle::user_database, ::doodle::user_database, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_update_user_date_, context, request);
}

::grpc::ClientAsyncResponseReader< ::doodle::user_database>* metadata_server::Stub::Asyncupdate_user_dateRaw(::grpc::ClientContext* context, const ::doodle::user_database& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncupdate_user_dateRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status metadata_server::Stub::delete_user_date(::grpc::ClientContext* context, const ::doodle::user_database_filter& request, ::doodle::user_database* response) {
  return ::grpc::internal::BlockingUnaryCall< ::doodle::user_database_filter, ::doodle::user_database, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_delete_user_date_, context, request, response);
}

void metadata_server::Stub::experimental_async::delete_user_date(::grpc::ClientContext* context, const ::doodle::user_database_filter* request, ::doodle::user_database* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::doodle::user_database_filter, ::doodle::user_database, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_delete_user_date_, context, request, response, std::move(f));
}

void metadata_server::Stub::experimental_async::delete_user_date(::grpc::ClientContext* context, const ::doodle::user_database_filter* request, ::doodle::user_database* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_delete_user_date_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::doodle::user_database>* metadata_server::Stub::PrepareAsyncdelete_user_dateRaw(::grpc::ClientContext* context, const ::doodle::user_database_filter& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::doodle::user_database, ::doodle::user_database_filter, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_delete_user_date_, context, request);
}

::grpc::ClientAsyncResponseReader< ::doodle::user_database>* metadata_server::Stub::Asyncdelete_user_dateRaw(::grpc::ClientContext* context, const ::doodle::user_database_filter& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncdelete_user_dateRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::ClientReader< ::doodle::user_database>* metadata_server::Stub::filter_user_dateRaw(::grpc::ClientContext* context, const ::doodle::user_database_filter& request) {
  return ::grpc::internal::ClientReaderFactory< ::doodle::user_database>::Create(channel_.get(), rpcmethod_filter_user_date_, context, request);
}

void metadata_server::Stub::experimental_async::filter_user_date(::grpc::ClientContext* context, const ::doodle::user_database_filter* request, ::grpc::experimental::ClientReadReactor< ::doodle::user_database>* reactor) {
  ::grpc::internal::ClientCallbackReaderFactory< ::doodle::user_database>::Create(stub_->channel_.get(), stub_->rpcmethod_filter_user_date_, context, request, reactor);
}

::grpc::ClientAsyncReader< ::doodle::user_database>* metadata_server::Stub::Asyncfilter_user_dateRaw(::grpc::ClientContext* context, const ::doodle::user_database_filter& request, ::grpc::CompletionQueue* cq, void* tag) {
  return ::grpc::internal::ClientAsyncReaderFactory< ::doodle::user_database>::Create(channel_.get(), cq, rpcmethod_filter_user_date_, context, request, true, tag);
}

::grpc::ClientAsyncReader< ::doodle::user_database>* metadata_server::Stub::PrepareAsyncfilter_user_dateRaw(::grpc::ClientContext* context, const ::doodle::user_database_filter& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncReaderFactory< ::doodle::user_database>::Create(channel_.get(), cq, rpcmethod_filter_user_date_, context, request, false, nullptr);
}

metadata_server::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      metadata_server_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< metadata_server::Service, ::doodle::metadata_database, ::doodle::metadata_database, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](metadata_server::Service* service,
             ::grpc::ServerContext* ctx,
             const ::doodle::metadata_database* req,
             ::doodle::metadata_database* resp) {
               return service->install_metadata(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      metadata_server_method_names[1],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< metadata_server::Service, ::doodle::metadata_database, ::doodle::metadata_database, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](metadata_server::Service* service,
             ::grpc::ServerContext* ctx,
             const ::doodle::metadata_database* req,
             ::doodle::metadata_database* resp) {
               return service->delete_metadata(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      metadata_server_method_names[2],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< metadata_server::Service, ::doodle::metadata_database, ::doodle::metadata_database, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](metadata_server::Service* service,
             ::grpc::ServerContext* ctx,
             const ::doodle::metadata_database* req,
             ::doodle::metadata_database* resp) {
               return service->update_metadata(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      metadata_server_method_names[3],
      ::grpc::internal::RpcMethod::SERVER_STREAMING,
      new ::grpc::internal::ServerStreamingHandler< metadata_server::Service, ::doodle::metadata_database_filter, ::doodle::metadata_database>(
          [](metadata_server::Service* service,
             ::grpc::ServerContext* ctx,
             const ::doodle::metadata_database_filter* req,
             ::grpc::ServerWriter<::doodle::metadata_database>* writer) {
               return service->filter_metadata(ctx, req, writer);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      metadata_server_method_names[4],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< metadata_server::Service, ::doodle::user_database, ::doodle::user_database, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](metadata_server::Service* service,
             ::grpc::ServerContext* ctx,
             const ::doodle::user_database* req,
             ::doodle::user_database* resp) {
               return service->install_user_date(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      metadata_server_method_names[5],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< metadata_server::Service, ::doodle::user_database, ::doodle::user_database, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](metadata_server::Service* service,
             ::grpc::ServerContext* ctx,
             const ::doodle::user_database* req,
             ::doodle::user_database* resp) {
               return service->update_user_date(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      metadata_server_method_names[6],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< metadata_server::Service, ::doodle::user_database_filter, ::doodle::user_database, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](metadata_server::Service* service,
             ::grpc::ServerContext* ctx,
             const ::doodle::user_database_filter* req,
             ::doodle::user_database* resp) {
               return service->delete_user_date(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      metadata_server_method_names[7],
      ::grpc::internal::RpcMethod::SERVER_STREAMING,
      new ::grpc::internal::ServerStreamingHandler< metadata_server::Service, ::doodle::user_database_filter, ::doodle::user_database>(
          [](metadata_server::Service* service,
             ::grpc::ServerContext* ctx,
             const ::doodle::user_database_filter* req,
             ::grpc::ServerWriter<::doodle::user_database>* writer) {
               return service->filter_user_date(ctx, req, writer);
             }, this)));
}

metadata_server::Service::~Service() {
}

::grpc::Status metadata_server::Service::install_metadata(::grpc::ServerContext* context, const ::doodle::metadata_database* request, ::doodle::metadata_database* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status metadata_server::Service::delete_metadata(::grpc::ServerContext* context, const ::doodle::metadata_database* request, ::doodle::metadata_database* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status metadata_server::Service::update_metadata(::grpc::ServerContext* context, const ::doodle::metadata_database* request, ::doodle::metadata_database* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status metadata_server::Service::filter_metadata(::grpc::ServerContext* context, const ::doodle::metadata_database_filter* request, ::grpc::ServerWriter< ::doodle::metadata_database>* writer) {
  (void) context;
  (void) request;
  (void) writer;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status metadata_server::Service::install_user_date(::grpc::ServerContext* context, const ::doodle::user_database* request, ::doodle::user_database* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status metadata_server::Service::update_user_date(::grpc::ServerContext* context, const ::doodle::user_database* request, ::doodle::user_database* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status metadata_server::Service::delete_user_date(::grpc::ServerContext* context, const ::doodle::user_database_filter* request, ::doodle::user_database* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status metadata_server::Service::filter_user_date(::grpc::ServerContext* context, const ::doodle::user_database_filter* request, ::grpc::ServerWriter< ::doodle::user_database>* writer) {
  (void) context;
  (void) request;
  (void) writer;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace doodle

