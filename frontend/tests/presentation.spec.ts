import { expect, test } from "@playwright/test";

test("judge can run the complete forensic story", async ({ page }) => {
  await page.goto("/fleet");
  await expect(page.getByRole("heading", { name: "Fleet overview" })).toBeVisible();
  await page.getByRole("link", { name: "Open investigation" }).click();
  await page.getByRole("button", { name: "Start collection" }).click();
  await expect(page.getByRole("dialog", { name: "Review collection" })).toContainText("Mock execution");
  await page.getByRole("button", { name: "Run collection" }).click();
  await expect(page.getByRole("link", { name: "Explore evidence" })).toBeVisible({ timeout: 8_000 });
  await page.getByRole("link", { name: "Explore evidence" }).click();
  await page.getByRole("tab", { name: "Network" }).click();
  await page.getByRole("button", { name: /powershell.exe connected to 198.51.100.42:443/i }).click();
  await expect(page.getByRole("dialog", { name: "Evidence record" })).toContainText("Mock evidence for presentation");
  await page.getByRole("button", { name: "Close evidence" }).click();
  await page.getByRole("link", { name: "Build proof" }).click();
  await expect(page.getByText("Checked-in evaluation sample")).toBeVisible();
  await expect(page.getByText(/31bc56ed1f21a961/)).toBeVisible();
});
