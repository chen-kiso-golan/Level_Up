import React, { useState, useEffect } from "react";
import { getAllCompaniesNamesFromDB } from "../../services/BuisnessCompaniesServices";
import { useAuth0 } from "@auth0/auth0-react";

export function ChooseCompanyRow({ chooseCompany }) {
  const [AllCompanies, setAllCompanies] = useState([]);
  const { user } = useAuth0();

  const getDB = async () => {
    let result = await getAllCompaniesNamesFromDB(user.email);
    setAllCompanies(result.data);
  };

  useEffect(() => {
    getDB();
  }, []);

  return (
    <>
      <label htmlFor="Company" className="frm-lbl">
        Company
      </label>
      <select name="Company" className="form-select" aria-label="Default select example" onChange={(event) => chooseCompany(event.target.value)}>
        <option defaultValue={"Choose The Name Of Your Company"}>Choose The Name Of Your Company</option>
        {AllCompanies.length > 0 ? (
          AllCompanies.map((Company) => {
            return (
              <>
                <option value={Company.Name}>{Company.Name}</option>
              </>
            );
          })
        ) : (
          <option value="1">There are no Companies.</option>
        )}
      </select>
    </>
  );
}
