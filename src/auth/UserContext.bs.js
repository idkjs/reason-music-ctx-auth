

import * as React from "react";

function initValue_001(param) {
  return /* () */0;
}

var initValue = /* tuple */[
  /* Anonymous */0,
  initValue_001
];

var context = React.createContext(initValue);

function makeProps(value, children, param) {
  return {
          value: value,
          children: children
        };
}

var make = context.Provider;

var Provider = {
  makeProps: makeProps,
  make: make
};

function useUser(param) {
  return React.useContext(context);
}

export {
  initValue ,
  context ,
  Provider ,
  useUser ,
  
}
/* context Not a pure module */
