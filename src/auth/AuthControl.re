// open SharedTypes;
open ReactUtils;

[@react.component]
let make = () => {
  let (user, dispatch) = UserContext.useUser();
  let (username, setUsername) = React.useState(() => "idkjs");
  let (password, setPassword) = React.useState(() => "fakejson");
  let handleSignin = () =>
    Js.Promise.(
      Auth.signIn(~username, ~password)
      |> then_(_res => {
          //  let x = res->AuthTypes.fromJs;
          //  let userData:AuthTypes.userData = {
          //    isLoggedIn: true,
          //    username: Js.Nullable.return(x.username),
          //    id: Js.Nullable.return(x.attributes.sub),
          //    email: Js.Nullable.return(x.attributes.email),
          //  };
           //  let userInfo: AuthTypes.userInfo = {username: user##username, attributes: user##attributes};
           Js.log("sign up success!");
          //  Js.log(userData);
          //  dispatch(UserLoggedIn(userData));
          //  setUser(_ => Some(userInfo));
           //  let formTypeToUpdate: FormTypes.formType = SignUp;
           //  updateFormType(_ => SignUp);
           resolve();
         })
      |> catch(err => {
           Js.log(err);
           let errMsg = "error signing up.." ++ Js.String.make(err);
           Js.log(errMsg);
           resolve();
         })
      |> ignore
    );

  switch (user) {
  | Anonymous =>
    <form
      className="user-form"
      onSubmit={e => {
        ReactEvent.Form.preventDefault(e);
        handleSignin();
      }}>
      <div className="field">
        <label className="label"> "Username"->React.string </label>
        <div className="control has-icons-left has-icons-right">
          <input
            className="input is-success"
            type_="text"
            placeholder="User name"
            value=username
            onChange={e => {
              let value = ReactEvent.Form.target(e)##value;
              setUsername(_ => value);
            }}
          />
          <span className="icon is-small is-left">
            <i className="fas fa-user" />
          </span>
          <span className="icon is-small is-right">
            <i className="fas fa-check" />
          </span>
        </div>
        <p className="help is-success">
          "This username is available"->React.string
        </p>
      </div>
      <div className="field">
        <label className="label"> "Password"->React.string </label>
        <div className="control has-icons-left has-icons-right">
          <input
            className="input is-success"
            type_="text"
            placeholder="Password"
            value=password
            onChange={e => {
              let value = ReactEvent.Form.target(e)##value;
              setPassword(_ => value);
            }}
          />
          <span className="icon is-small is-left">
            <i className="fas fa-user" />
          </span>
          <span className="icon is-small is-right">
            <i className="fas fa-check" />
          </span>
        </div>
      </div>
      <div className="control">
        <button type_="submit" className="button is-link">
          {s("Log in")}
        </button>
      </div>
    </form>
  | LoggedIn(user) =>
  // let name = Js.Nullable.toOption(userData.username)->Belt.Option.getWithDefault("");
    <div className="user-form">
      <span className="logged-in">
        {s("Logged in as: ")}
        <b> {s(user.username)} </b>
      </span>
      <div className="control">
        <button
          className="button is-link" onClick={_ => dispatch(UserLoggedOut)}>
          {s("Log Out")}
        </button>
      </div>
    </div>
  };
};