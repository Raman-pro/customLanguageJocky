import { render, screen } from "@testing-library/react";
import { MemoryRouter } from "react-router-dom";
import { DemoProvider } from "../../app/DemoProvider";
import { FleetPage } from "./FleetPage";

function renderFleet() {
  return render(
    <MemoryRouter>
      <DemoProvider>
        <FleetPage />
      </DemoProvider>
    </MemoryRouter>,
  );
}

it("presents the complete three-host incident scope", async () => {
  renderFleet();

  expect(await screen.findByRole("heading", { name: "Fleet overview" })).toBeVisible();
  expect(screen.getByText("FIN-WS-07")).toBeVisible();
  expect(screen.getByText("DC-WIN-01")).toBeVisible();
  expect(screen.getByText("ENG-UBU-02")).toBeVisible();
  expect(screen.getByText("Suspected lateral movement")).toBeVisible();
  expect(screen.getByRole("link", { name: /open investigation/i })).toHaveAttribute("href", "/cases/JKY-104");
});
