import React, { useState, useEffect } from "react";
import "./homestyle.css";

export const Home = () => {
  const [currentSlide, setCurrentSlide] = useState(0);
  const [showModal, setShowModal] = useState(false);
  const [infoType, setInfoType] = useState("");

  useEffect(() => {
    const intervalId = setInterval(() => {
      setCurrentSlide((currentSlide + 1) % 3);
    }, 2000);
    return () => clearInterval(intervalId);
  }, [currentSlide]);

  const handleModalOpen = (UserType) => {
    setInfoType(UserType);
    setShowModal(true);
  };
  const handleModalReturn = () => {
    setShowModal(false);
  };

  return (
    <div className="CarouselComponent--container">
      <div
        id="carouselExampleDark"
        class="carousel carousel-dark slide"
        data-bs-ride="carousel"
      >
        <div className="carousel-indicators"></div>
        <div className="carousel-inner">
          <div
            className={`carousel-item ${currentSlide === 0 ? "active" : ""}`}
            data-bs-interval="10000"
          >
            <img
              src="https://www.planstreetinc.com/wp-content/uploads/2022/09/Social-Services-960x720.jpg"
              className="d-block w-100"
              alt="..."
            />
            <div className="carousel-caption d-none d-md-block">
              <h5>Non Profit Organization</h5>
              <p>
                As a non-profit organization you can promote social agendas and
                receive donations from companies and activists.
              </p>
              <label
                className="btn-info"
                onClick={() => handleModalOpen("NPO")}
              >
                More Info!
              </label>
            </div>
          </div>
          <div
            className={`carousel-item ${currentSlide === 1 ? "active" : ""}`}
            data-bs-interval="2000"
          >
            <img
              src="https://www.taxmann.com/post/wp-content/uploads/2021/04/company-concept-illustration_114360-2581.jpg"
              className="d-block w-100"
              alt="..."
            />
            <div className="carousel-caption d-none d-md-block">
              <h5>Buissnes Campenies</h5>
              <p>
                As a business company you can cooperate with selected campaigns
                and social activists can donate your products to these
                campaigns.
              </p>
              <label className="btn-info" onClick={() => handleModalOpen("BC")}>
                More Info!
              </label>
            </div>
          </div>
          <div
            className={`carousel-item ${currentSlide === 2 ? "active" : ""}`}
          >
            <img
              src="https://static.vecteezy.com/system/resources/previews/007/128/254/original/illustration-graphic-cartoon-character-of-social-activists-and-demonstrations-demanding-improvement-free-vector.jpg"
              className="d-block w-100"
              alt="..."
            />
            <div className="carousel-caption d-none d-md-block">
              <h5>Social Activists</h5>
              <p>
                As a social activist you will be able to donate products to a
                campaign you want to promote using money you will earn from
                promoting the campaign on social networks.
              </p>
              <label className="btn-info" onClick={() => handleModalOpen("SA")}>
                More Info!
              </label>
            </div>
          </div>
        </div>
      </div>
      {showModal && (
        <div className="modal-container">
          <div className="modal-content">
            {infoType === "NPO" && (
              <>
                <h2>Non Profit Organization</h2>
                <h6>
                  As a non-profit organization you can promote social agendas
                  and receive donations from companies and activists.
                </h6>
                <br />
                <p>
                  every time a social activist promote your campaign on social
                  media we will reward him with money!
                </p>
                <br />
                <p>
                  after the social activits earns enough money he can donate to
                  your campaign a product that will be suplied by buisness
                  compenies that accoiate with your campaign.
                </p>
              </>
            )}
            {infoType === "BC" && (
              <>
                <h2>Business Company</h2>
                <h6>
                  As a business company you can cooperate with selected
                  campaigns and social activists can donate your products to
                  these campaigns.
                </h6>
                <br />
                <p>
                  every time a social activists will buy a product from you we
                  will update you in our orders panel for you convince!
                </p>
                <br />
                <p>
                  every time a social activist will donate your products we will
                  promote your products on our social media!
                </p>
              </>
            )}
            {infoType === "SA" && (
              <>
                <h2>Social Activist</h2>
                <h6>
                  As a social activist you will be able to donate products to a
                  campaign you want to promote using money you will earn from
                  promoting the campaign on social networks.
                </h6>
                <br />
                <p>
                  every time you promote the campaign you chosed on social media
                  we will give you 1 dollar!
                </p>
                <br />
              </>
            )}
            <div className="modal-btn">
              <button className="btn btn-danger" onClick={handleModalReturn}>
                Return
              </button>
            </div>
          </div>
        </div>
      )}
    </div>
  );
};
