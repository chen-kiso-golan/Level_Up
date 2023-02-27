import React from "react";
import { useNavigate } from "react-router-dom";
import "./styleRegister.css";

export const RegisterType = () => {
  const navigate = useNavigate();

  const handelRegisterType = (Role) => {
    navigate("/registerTypeForm", {
      state: {
        Role,
      },
    });
  };

  return (
    <div className="RegisterType--container card-group">
      <div className="RegisterType--Company card">
        <img
          src="https://www.taxmann.com/post/wp-content/uploads/2021/04/company-concept-illustration_114360-2581.jpg"
          className="card-img-top"
          alt="..."
        />
        <div className="card-body">
          <h5 className="card-title">Company</h5>
          <p className="card-text">
            Welcome to our site, we believe that if everyone contributes a
            little of what they can we will create a beautiful society.
            Congratulations on your contribution as a company.
          </p>
        </div>
        <div className="card-footer">
          <button
            onClick={() => handelRegisterType("Company")}
            className="btn btn-outline-success"
          >
            Register
          </button>
        </div>
      </div>
      <div className="RegisterType--SocialActivist card">
        <img
          src="https://static.vecteezy.com/system/resources/previews/007/128/254/original/illustration-graphic-cartoon-character-of-social-activists-and-demonstrations-demanding-improvement-free-vector.jpg"
          className="card-img-top"
          alt="..."
        />
        <div className="card-body">
          <h5 className="card-title">Social Activist</h5>
          <p className="card-text">
            Welcome to our site, we believe that if everyone contributes a
            little of what they can we will create a beautiful society. We are
            happy to hear that there are people like you who are willing to give
            with love to human society.
          </p>
        </div>
        <div className="card-footer">
          <button
            onClick={() => handelRegisterType("Social_Activist")}
            className="btn btn-outline-success"
          >
            Register
          </button>
        </div>
      </div>
      <div className="RegisterType--NonProfitOrganization card">
        <img
          src="https://www.planstreetinc.com/wp-content/uploads/2022/09/Social-Services-960x720.jpg"
          className="card-img-top"
          alt="..."
        />
        <div className="card-body">
          <h5 className="card-title">Non Profit Organization</h5>
          <p className="card-text">
            Welcome to our site, we believe that if everyone contributes a
            little of what they can we will create a beautiful society. As a
            non-profit organization, you are a beacon for the people who are
            easy to miss.
          </p>
        </div>
        <div className="card-footer">
          <button
            onClick={() => handelRegisterType("NPO")}
            className="btn btn-outline-success"
          >
            Register
          </button>
        </div>
      </div>
    </div>
  );
};
