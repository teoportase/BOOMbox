var babylonInterop = babylonInterop || {};

babylonInterop.initCanvas = function (canvasID) {
    var babylonCanvas = document.getElementById(canvasID);
    var babylonEngine = new BABYLON.Engine(babylonCanvas, true);
    var scene = babylonInterop.createSceneWithSphere(babylonEngine, babylonCanvas);

    babylonEngine.runRenderLoop(function () {
        scene.render();
    });

    window.addEventListener("resize", function () {
        babylonEngine.resize();
    });
};

babylonInterop.createSceneWithSphere = function (engine, canvas) {
    var scene = new BABYLON.Scene(engine);
    scene.clearColor = new BABYLON.Color4(0.5, 0.8, 0.5); // Set scene color

    var camera = new BABYLON.ArcRotateCamera("Camera", -Math.PI / 2, Math.PI / 2.5, 3, new BABYLON.Vector3(0, 0, 0), scene);
    camera.attachControl(canvas, true);

    var light1 = new BABYLON.HemisphericLight("light", new BABYLON.Vector3(0, 1, 0), scene);

    // I tried putting the model in a different directory but it didn't work
    var kirby = BABYLON.SceneLoader.ImportMeshAsync("", "../assets/","Kirby.glb", scene);

    return scene;
};