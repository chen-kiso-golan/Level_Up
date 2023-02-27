import React, { useState, useEffect, useContext } from "react";
import { getAllProductsFromDB } from "../../services/ProductsServices";
import { getBcCodeByEmailFromDB } from "../../services/BuisnessCompaniesServices";
import { getCampaignNameAndHashtagByCodeFromDB } from "../../services/CampaignsServices";
import { MakeA_TweetInTwitter } from "../../services/twitterServices";
import { addOrderToDB } from "../../services/OrdersServices";
import { RoleStatus } from "../../context/roleStatus";
import { useAuth0 } from "@auth0/auth0-react";
import { UserDataContext } from "./../../context/UserData";

export const ProductsReportRow = (props) => {
  const [AllProducts, setAllProducts] = useState([]);
  const [userBCcode, setuserBCcode] = useState([]);
  const { role } = useContext(RoleStatus);
  const { user } = useAuth0();
  const { UserInfo } = useContext(UserDataContext);

  const getDB = async () => {
    let result = await getAllProductsFromDB();
    let userBCcode = await getBcCodeByEmailFromDB(user.email);
    setAllProducts(result.data);
    setuserBCcode(userBCcode);
  };

  useEffect(() => {
    getDB();
  }, []);

  const handelDonationData = async (Product) => {
    await addOrderToDB(Product);
    let NameAndHashtag = await getCampaignNameAndHashtagByCodeFromDB(Product.Campaign_code);
    const InfoForTweet = {
      Twitter_Name: UserInfo.Twitter_Name,
      ProductName: Product.Name,
      CampaignName: NameAndHashtag[0].Name,
      CampaignHashtag: NameAndHashtag[0].Hashtag,
      ProductPrice: Product.Price,
      SACode: UserInfo.SACode,
    };
    await MakeA_TweetInTwitter(InfoForTweet);
  };

  return (
    <>
      {AllProducts.length > 0 ? (
        AllProducts.map((Product) => {
          let { Code, Name, Price, Units_In_Stock, BC_code, Campaign_code, Image } = Product;
          return (
            <>
              <tr className={role !== "SA" && userBCcode === BC_code ? "table-danger" : ""}>
                <th scope="row">{Code}</th>
                <td>{Name}</td>
                <td>{Price}$</td>
                <td>{Units_In_Stock}</td>
                <td>{BC_code}</td>
                <td>{Campaign_code}</td>
                <td>
                  <img style={{ width: "50px", height: "50px", borderRadius: "30%" }} src={Image} alt="" />
                </td>
                {role === "SA" && (
                  <td>
                    <button type="button" className="btn btn-primary" onClick={() => handelDonationData(Product)}>
                      Buy & Donate
                    </button>
                  </td>
                )}
              </tr>
            </>
          );
        })
      ) : (
        <h1>There are no products.</h1>
      )}
    </>
  );
};
