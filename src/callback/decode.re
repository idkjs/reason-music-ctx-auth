[@bs.deriving abstract]
type hubPayloadJs = {
  event: string,
  data: option(Js.Json.t),
  message: option(string),
};
type hubPayload = {
  event: string,
  data: option(Js.Json.t),
  message: option(string),
};

let decodePayload: hubPayloadJs => hubPayload =
  data => {
    event: data->eventGet,
    data: data->dataGet,
    message: data->messageGet,
  };
// [@bs.module "./hubcallback.json"] external res: Js.t('a) = "default";
// let payloadJs = res##payload |> Obj.magic;
// let payload = decodePayload(payloadJs);
[@bs.deriving abstract]
type hubCapsuleJs = {
  channel: string,
  payload: hubPayload,
  source: string,
  patternInfo: option(array(string)),
};
type hubCapsule = {
  channel: string,
  payload: hubPayload,
  source: string,
  patternInfo: option(array(string)),
};
[@bs.module "./hubcallback.json"] external res: Js.t('a) = "default";
let decode: hubCapsuleJs => hubCapsule =
  data => {
    channel: data->channelGet,
    payload: res##payload->decodePayload,
    source: data->sourceGet,
    patternInfo: data->patternInfoGet,
  };

Js.log2("bc", res);
external castTohubCapsuleJs: 'a => hubCapsuleJs = "%identity";
let hubcb = res => res->castTohubCapsuleJs;
let cb = res->castTohubCapsuleJs;
Js.log2("bc", cb) /* Js.log2("event", cb.payload->eventGet)*/ /* let cb = res->decode*/;
// [@bs.module "./hubcallback.json"] external res: hubCapsuleJs = "default";