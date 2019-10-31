// open SharedTypes;
open AuthTypes;

type dispatch = userAction => unit;
type contextValue = (user, dispatch);

type context = contextValue => React.Context.t(contextValue);

let initValue: contextValue = (Anonymous, _ => ignore());
let context = React.createContext(initValue);

module Provider = {
  let makeProps = (~value, ~children, ()) => {
    "value": value,
    "children": children,
  };
  let make = React.Context.provider(context);
};
let useUser = () => React.useContext(context);

