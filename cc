<!DOCTYPE html>
<html lang="th">
<head>
  <meta charset="UTF-8">
  <title>รับแสตมป์</title>
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <script src="https://static.line-scdn.net/liff/edge/2/sdk.js"></script>
  <style>
    body { font-family: sans-serif; text-align: center; padding: 2rem; background: #f0f8ff; }
    #status { font-size: 1.4rem; margin-top: 2rem; }
  </style>
</head>
<body>
  <h2>🎁 รับแสตมป์กิจกรรม</h2>
  <div id="status">กำลังโหลด...</div>
  <script>
    const EVENT_CODE = "promo0626"; // เปลี่ยนได้ตามกิจกรรม
    const SCRIPT_URL = "https://script.google.com/macros/s/AKfycbx0IbnDRG7onXEkU_8d2-iMUM5E-pSZt28mlwdYEJ08o2Clmzrim80_-APLNe8XmziK/exec"; // ใส่ Apps Script URL ของคุณ

    async function main() {
      await liff.init({ liffId: "2004387490" }); // <== ใส่ LIFF ID
      if (!liff.isLoggedIn()) {
        liff.login();
        return;
      }

      const profile = await liff.getProfile();
      const userId = profile.userId;
      const res = await fetch(`${SCRIPT_URL}?uid=${userId}&event=${EVENT_CODE}`);
      const text = await res.text();
      document.getElementById("status").innerText = text;
    }

    main();
  </script>
</body>
</html>
