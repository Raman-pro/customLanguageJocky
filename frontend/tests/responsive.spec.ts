import { expect, test } from "@playwright/test";

const routes = ["/fleet", "/cases/JKY-104", "/cases/JKY-104/evidence", "/builds/forensics-l3"];
const widths = [1440, 1024, 768, 390];

for (const width of widths) {
  test(`primary screens avoid horizontal overflow at ${width}px`, async ({ page }) => {
    await page.setViewportSize({ width, height: width <= 390 ? 844 : 900 });
    for (const route of routes) {
      await page.goto(route);
      await page.locator("main").waitFor();
      await page.evaluate(() => document.fonts.ready);
      if (route.endsWith("evidence")) await page.locator(".evidence-row-action").first().waitFor();
      const hasHorizontalOverflow = await page.evaluate(
        () => document.documentElement.scrollWidth > document.documentElement.clientWidth,
      );
      expect(hasHorizontalOverflow, `${route} overflowed at ${width}px`).toBe(false);
    }
  });
}

test("mobile navigation stays visible and evidence inspector uses the full viewport", async ({ page }) => {
  await page.setViewportSize({ width: 390, height: 844 });
  await page.goto("/fleet");
  const navBox = await page.getByRole("navigation", { name: "Primary navigation" }).boundingBox();
  expect(navBox).not.toBeNull();
  expect(navBox!.y).toBeGreaterThanOrEqual(0);
  expect(navBox!.y + navBox!.height).toBeLessThan(200);
  await expect(page.getByRole("link", { name: "Investigation", exact: true })).toBeVisible();

  await page.goto("/cases/JKY-104/evidence?finding=F-001");
  const inspector = page.getByRole("dialog", { name: "Evidence record" });
  await expect(inspector).toBeVisible();
  const inspectorBox = await inspector.boundingBox();
  expect(inspectorBox?.width).toBeCloseTo(390, 3);
});
