

import * as Block from "bs-platform/lib/es6/block.js";
import * as AwsAmplify from "aws-amplify";
import * as Amplify$ReasonMusicCtx from "./Amplify.bs.js";

var currentAuthenticatedUser = AwsAmplify.Auth.currentAuthenticatedUser().then((function (res) {
        return Promise.resolve(res);
      }));

function signIn(username, password) {
  return AwsAmplify.Auth.signIn(username, password).then((function (res) {
                return Promise.resolve(res);
              }));
}

function signUp(username, password, attributes) {
  return AwsAmplify.Auth.signUp(username, password, attributes).then((function (res) {
                return Promise.resolve(res);
              }));
}

function confirmSignUp(username, confirmationCode) {
  return AwsAmplify.Auth.confirmSignUp(username, confirmationCode).then((function (res) {
                return Promise.resolve(res);
              }));
}

function forgotPassword(username) {
  return AwsAmplify.Auth.forgotPassword(username).then((function (res) {
                return Promise.resolve(res);
              }));
}

function forgotPasswordSubmit(username, confirmationCode, password) {
  return AwsAmplify.Auth.forgotPasswordSubmit(username, confirmationCode, password).then((function (res) {
                return Promise.resolve(res);
              }));
}

function currentUserPoolUser(userPoolId) {
  return AwsAmplify.Auth.currentUserPoolUser(userPoolId).then((function (res) {
                return Promise.resolve(res);
              }));
}

function checkUser(param) {
  currentUserPoolUser(Amplify$ReasonMusicCtx.Config.userPoolId).then((function (res) {
            return Promise.resolve(res);
          })).catch((function (error) {
          console.log("error", error);
          return Promise.resolve(/* Error */Block.__(1, [error]));
        }));
  return /* () */0;
}

function signOut(param) {
  AwsAmplify.Auth.signOut().then((function (data) {
            console.log("signOut_data: ", data);
            return Promise.resolve(/* Ok */Block.__(0, [data]));
          })).catch((function (error) {
          console.log("error", error);
          return Promise.resolve(/* Error */Block.__(1, [error]));
        }));
  return /* () */0;
}

export {
  currentAuthenticatedUser ,
  signIn ,
  signUp ,
  confirmSignUp ,
  forgotPassword ,
  forgotPasswordSubmit ,
  currentUserPoolUser ,
  checkUser ,
  signOut ,
  
}
/* currentAuthenticatedUser Not a pure module */
