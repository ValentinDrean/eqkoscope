#ifndef BORING_ANGEL_AbstractApp_h
#define BORING_ANGEL_AbstractApp_h

#include <ofBaseTypes.h>
#include <stdlib.h>
#include "pdefinition.h"

#include "ofxIldaFrame.h"

#define MIDI_CC 0
#define MIDI_NOTEON 1
#define MIDI_NOTEOFF 2

using namespace std;

class AbstractApp
{
public:
    
    ofColor getRandomColor(){
        cout << "hsb " << parameterMap[tintCenter]*255 << " " << ofRandom(-parameterMap[tintAmp]/2.0, parameterMap[tintAmp]/2.0)*255.0f << " " <<endl;
        return ofColor::fromHsb(fmod(parameterMap[tintCenter]*255 + ofRandom(-parameterMap[tintAmp]/2.0, parameterMap[tintAmp]/2.0)*255.0f + 255.0f, 255.0f), parameterMap[sidesSaturation]*255, 255);
    }
    
    void initParameterMap(){
        
        
        parameterNameMap["post_traitement"]=post_traitement;
        parameterNameMap["omg3D"]=omg3D;
        parameterNameMap["omg3DAngle"]=omg3DAngle;
        parameterNameMap["test"]=test;
        parameterNameMap["test2"]=test2;
        parameterNameMap["test3"]=test3;
        parameterNameMap["omg3D2"]=omg3D2;
        parameterNameMap["omg3D2Dist"]=omg3D2Dist;
        parameterNameMap["omg3D2Y"]=omg3D2Y;
        parameterNameMap["omg3D2Alpha0"]=omg3D2Alpha0;
        parameterNameMap["omg3D2AlphaZ"]=omg3D2AlphaZ;
        parameterNameMap["omg3D2RollerX"]=omg3D2RollerX;
        parameterNameMap["omg3D2RollerY"]=omg3D2RollerY;
        parameterNameMap["omg3D2Symetry"]=omg3D2Symetry;
        parameterNameMap["omg3D2Rotation"]=omg3D2Rotation;
        parameterNameMap["omg3D2Divergence"]=omg3D2Divergence;
        parameterNameMap["omg3D2Speed"]=omg3D2Speed;
        parameterNameMap["omg3D2FreeRotation"]=omg3D2FreeRotation;
        parameterNameMap["omg3D2AvoidCenter"]=omg3D2AvoidCenter;
        parameterNameMap["ball"]=ball;
        parameterNameMap["thresholdAfterBall"]=thresholdAfterBall;
        parameterNameMap["kinectScale"]=kinectScale;
        parameterNameMap["kinectMasking"]=kinectMasking;
        parameterNameMap["glowResolution"]=glowResolution;
        parameterNameMap["glowIntensity"]=glowIntensity;
        parameterNameMap["randHHide"]=randHHide;
        parameterNameMap["randVHide"]=randVHide;
        parameterNameMap["glow"]=glow;
        parameterNameMap["sobel"]=sobel;
        parameterNameMap["sobelMix"]=sobelMix;
        parameterNameMap["gradient"]=gradient;
        parameterNameMap["contrast"]=contrast;
        parameterNameMap["invert"]=_invert;
        parameterNameMap["vblur"]=vblur;
        parameterNameMap["hblur"]=hblur;
        parameterNameMap["blurOriginalMix"]=blurOriginalMix;
        parameterNameMap["sharpen"]=sharpen;
        parameterNameMap["sharpenMode"]=sharpenMode;
        parameterNameMap["nBlocks"]=nBlocks;
        parameterNameMap["nFreeze"]=nFreeze;
        parameterNameMap["strobe"]=strobe;
        parameterNameMap["xpixellate"]=xpixellate;
        parameterNameMap["ypixellate"]=ypixellate;
        parameterNameMap["embedUzi"]=embedUzi;
        parameterNameMap["embedCinema"]=embedCinema;
        parameterNameMap["threeDeeScene"]=threeDeeScene;
        parameterNameMap["toLine"]=toLine;
        parameterNameMap["toCircle"]=toCircle;
        parameterNameMap["lineDa"]=lineDa;
        parameterNameMap["lineDx"]=lineDx;
        parameterNameMap["blendType"]=blendType;
        parameterNameMap["flash"]=flash;
        parameterNameMap["triumMode"]=triumMode;
        parameterNameMap["triumSpace1"]=triumSpace1;
        parameterNameMap["triumSpace2"]=triumSpace2;
        parameterNameMap["triumSpace3"]=triumSpace3;
        parameterNameMap["warp"]=warp;
        parameterNameMap["mediaX"]=mediaX;
        parameterNameMap["mediaY"]=mediaY;
        parameterNameMap["mediaZ"]=mediaZ;
        parameterNameMap["mediaRotX"]=mediaRotX;
        parameterNameMap["mediaRotY"]=mediaRotY;
        parameterNameMap["mediaRotZ"]=mediaRotZ;
        parameterNameMap["paint"]=paint;
        parameterNameMap["multiFbos"]=multiFbos;
        parameterNameMap["tintSaturation"]=tintSaturation;
        parameterNameMap["tintHue"]=tintHue;
        parameterNameMap["tintBrightness"]=tintBrightness;
        parameterNameMap["black"]=black;
        parameterNameMap["tintCenter"]=tintCenter;
        parameterNameMap["tintAmp"]=tintAmp;
        parameterNameMap["sidesSaturation"]=sidesSaturation;
        parameterNameMap["reTint"]=_reTint;
        parameterNameMap["tintMode"]=tintMode;
        parameterNameMap["randomTint"]=randomTint;
        parameterNameMap["bpm"]=bpm;
        parameterNameMap["bpmLock"]=bpmLock;
        parameterNameMap["kalei"]=kalei;
        parameterNameMap["kaleiCopyBorder"]=kaleiCopyBorder;
        parameterNameMap["kaleiNb"]=kaleiNb;
        parameterNameMap["kalei_2"]=kalei_2;
        parameterNameMap["kaleiNb_2"]=kaleiNb_2;
        parameterNameMap["kaleiOffX"]=kaleiOffX;
        parameterNameMap["kaleiOffY"]=kaleiOffY;
        parameterNameMap["kaleiScale"]=kaleiScale;
        parameterNameMap["stripesAmp"]=stripesAmp;
        parameterNameMap["stripesSize"]=stripesSize;
        parameterNameMap["skewAmp"]=skewAmp;
        parameterNameMap["skewDAmp"]=skewDAmp;
        parameterNameMap["skewAAmp"]=skewAAmp;
        parameterNameMap["skewVAmp"]=skewVAmp;
        parameterNameMap["skewSpeed"]=skewSpeed;
        parameterNameMap["skewVAmpMi"]=skewVAmpMi;
        parameterNameMap["skewAmpMi"]=skewAmpMi;
        parameterNameMap["skewBorderCopy"]=skewBorderCopy;
        parameterNameMap["displaceAmp"]=displaceAmp;
        parameterNameMap["displaceVAmp"]=displaceVAmp;
        parameterNameMap["displaceProba"]=displaceProba;
        parameterNameMap["chromaOffset"]=chromaOffset;
        parameterNameMap["chromasepAngle"]=chromasepAngle;
        parameterNameMap["chromasepHue"]=chromasepHue;
        parameterNameMap["chromaSep"]=chromaSep;
        parameterNameMap["chromaSepAlpha"]=chromaSepAlpha;
        parameterNameMap["doubleChromaSep"]=doubleChromaSep;
        parameterNameMap["chromaSens"]=chromaSens;
        parameterNameMap["sortXThresh"]=sortXThresh;
        parameterNameMap["sortYThresh"]=sortYThresh;
        parameterNameMap["audio"]=audio;
        parameterNameMap["audioIn"]=_audioIn;
        parameterNameMap["carder"]=carder;
        parameterNameMap["dualFocus"]=dualFocus;
        parameterNameMap["dualFocusIntensity"]=dualFocusIntensity;
        parameterNameMap["currentScene"]=currentScene;
        parameterNameMap["antiAliasing"]=antiAliasing;
        parameterNameMap["FXMode"]=FXMode;
        parameterNameMap["skewUpdateRate"]=skewUpdateRate;
        parameterNameMap["skewJumpRate"]=skewJumpRate;
        parameterNameMap["skewHard"]=skewHard;
        parameterNameMap["skewBandingProb"]=skewBandingProb;
        parameterNameMap["skewBandingJumpProb"]=skewBandingJumpProb;
        parameterNameMap["omg3D2HardRotation"]=omg3D2HardRotation;
        parameterNameMap["omg3D2Nb"]=omg3D2Nb;
        parameterNameMap["kaleiCopy"]=kaleiCopy;
        parameterNameMap["kaleiCopyAdjust"]=kaleiCopyAdjust;
        parameterNameMap["warpRemap"]=warpRemap;
        parameterNameMap["warpX"]=warpX;
        parameterNameMap["warpY"]=warpY;
        parameterNameMap["stressTest"]=stressTest;
        parameterNameMap["stressTestRate"]=stressTestRate;
        parameterNameMap["reSaturate"]=reSaturate;
        parameterNameMap["prollage"]=prollage;
        parameterNameMap["dispose"]=dispose;
        parameterNameMap["disposeFreq"]=disposeFreq;
        parameterNameMap["disposeX"]=disposeX;
        parameterNameMap["leapAutoReco"]=leapAutoReco;
        parameterNameMap["hueShift"]=hueShift;
        parameterNameMap["hueShiftCenter"]=hueShiftCenter;
        parameterNameMap["hueShiftRange"]=hueShiftRange;
        parameterNameMap["hueShiftCrazy"]=hueShiftCrazy;
        parameterNameMap["kaleiMirror"]=kaleiMirror;
        parameterNameMap["omg3D2ZScale"]=omg3D2ZScale;
        parameterNameMap["omg3D2LumaKey"]=omg3D2LumaKey;
        parameterNameMap["invertCircle"]=invertCircle;
        parameterNameMap["debug"]=debug;
        parameterNameMap["agentSpeed"]=agentSpeed;
        parameterNameMap["agentNb"]=agentNb;
        parameterNameMap["agentShapeNb"]=agentShapeNb;
        parameterNameMap["agentShapeNbRand"]=agentShapeNbRand;
        parameterNameMap["agentNbShapes"]=agentNbShapes;
        parameterNameMap["agentFill"]=agentFill;
        parameterNameMap["agentRandDist"]=agentRandDist;
        parameterNameMap["agentAngleFreq"]=agentAngleFreq;
        parameterNameMap["feedMode"]=feedMode;
        parameterNameMap["nbPoints"]=nbPoints;
        parameterNameMap["mediaAlpha"]=mediaAlpha;
        parameterNameMap["mediaSaturation"]=mediaSaturation;
        parameterNameMap["blackCenter"]=blackCenter;
        parameterNameMap["pointx"]=pointx;
        parameterNameMap["pointy"]=pointy;
        parameterNameMap["feedbackRemanence"]=feedbackRemanence;
        parameterNameMap["noSource"]=noSource;
        parameterNameMap["erode"]=erode;
        parameterNameMap["fastErode"]=fastErode;
        parameterNameMap["threshold"]=threshold;
        parameterNameMap["rot"]=rot;
        parameterNameMap["upRot"]=upRot;
        parameterNameMap["pitchRot"]=pitchRot;
        parameterNameMap["scale"]=scale;
        parameterNameMap["offx"]=offx;
        parameterNameMap["offy"]=offy;
        parameterNameMap["pace"]=pace;
        parameterNameMap["f_strobe"]=f_strobe;
        parameterNameMap["f_invertFrame"]=f_invertFrame;
        parameterNameMap["doubleInversion"]=doubleInversion;
        parameterNameMap["backMask"]=backMask;
        parameterNameMap["curShapeRot"]=curShapeRot;
        parameterNameMap["shapeRot"]=shapeRot;
        parameterNameMap["shapeNbPts"]=shapeNbPts;
        parameterNameMap["shapeStyle"]=shapeStyle;
        parameterNameMap["shapeWeight"]=shapeWeight;
        parameterNameMap["randomShapeColor"]=randomShapeColor;
        parameterNameMap["randomText"]=randomText;
        parameterNameMap["seqText"]=seqText;
        parameterNameMap["randomFont"]=randomFont;
        parameterNameMap["txt_randPosition"]=txt_randPosition;
        parameterNameMap["txt_randSize"]=txt_randSize;
        parameterNameMap["nWords"]=nWords;
        parameterNameMap["txt_accumulate"]=txt_accumulate;
        parameterNameMap["txt_fill"]=txt_fill;
        parameterNameMap["fontSize"]=fontSize;
        parameterNameMap["txt_rate"]=txt_rate;
        parameterNameMap["wordLimit"]=wordLimit;
        parameterNameMap["updateLen"]=updateLen;
        parameterNameMap["speed"]=speed;
        parameterNameMap["lines_yWeight"]=lines_yWeight;
        parameterNameMap["lines_zWeight"]=lines_zWeight;
        parameterNameMap["lines_zSquare"]=lines_zSquare;
        parameterNameMap["lines_ySquare"]=lines_ySquare;
        parameterNameMap["lines_yres"]=lines_yres;
        parameterNameMap["lines_mesh"]=lines_mesh;
        parameterNameMap["crtPos"]=crtPos;
        parameterNameMap["posterize"]=posterize;
        parameterNameMap["movieSpeed"]=movieSpeed;
        parameterNameMap["transluscentUzi"]=transluscentUzi;
        parameterNameMap["gamma"]=_gamma;
        parameterNameMap["brightness"]=brightness;
        parameterNameMap["adjust"]=adjust;
        parameterNameMap["loopLength"]=loopLength;
        parameterNameMap["loopStart"]=loopStart;
        parameterNameMap["loopMode"]=loopMode;
        parameterNameMap["supZoom"]=supZoom;
        parameterNameMap["supRot"]=supRot;
        parameterNameMap["jumpTo"]=jumpTo;
        parameterNameMap["hMirror"]=hMirror;
        parameterNameMap["vMirror"]=vMirror;
        parameterNameMap["mixer"]=mixer;
        parameterNameMap["selectedPlayer"]=selectedPlayer;
        parameterNameMap["syncToTempo"]=syncToTempo;
        parameterNameMap["circle"]=circle;
        parameterNameMap["circleSpeed"]=circleSpeed;
        parameterNameMap["circleRotation"]=circleRotation;
        parameterNameMap["circleDist"]=circleDist;
        parameterNameMap["z"]=z;
        parameterNameMap["postT"]=postT;
        parameterNameMap["omg3D2YDivergence"]=omg3D2YDivergence;
        parameterNameMap["feedback"]=feedback;
        parameterNameMap["randomSpeed"]=randomSpeed;
        parameterNameMap["paint2"]=paint2;
        parameterNameMap["switchImg"]=switchImg;
        parameterNameMap["autoSwitchImg"]=autoSwitchImg;
        parameterNameMap["randomUzi"]=randomUzi;
        parameterNameMap["uziPeriod"]=uziPeriod;
        parameterNameMap["nextImg"]=nextImg;
        parameterNameMap["omg3D2X"]=omg3D2X;
        parameterNameMap["roundMask"]=roundMask;
        parameterNameMap["resize"]=resize;
        parameterNameMap["kenBurns"]=kenBurns;
        parameterNameMap["kenBurnsZ_end"]=kenBurnsZ_end;
        parameterNameMap["kenBurnsZ"]=kenBurnsZ;
        parameterNameMap["kenBurnsZ_pos"]=kenBurnsZ_pos;
        parameterNameMap["kenBurnsZ_min"]=kenBurnsZ_min;
        parameterNameMap["kenBurnsZ_max"]=kenBurnsZ_max;
        parameterNameMap["autoRot"]=autoRot;
        parameterNameMap["autoRotFreq"]=autoRotFreq;
        parameterNameMap["ak47Mode"]=ak47Mode;
        parameterNameMap["ak47Frame"]=ak47Frame;
        parameterNameMap["lastAk47Index"]=lastAk47Index;
        parameterNameMap["parallax"]=parallax;
        parameterNameMap["parallax_res"]=parallax_res;
        parameterNameMap["swapTint"]=swapTint;
        parameterNameMap["draw_recording"]=draw_recording;
        parameterNameMap["draw_maxConnectionLength"]=draw_maxConnectionLength;
        parameterNameMap["draw_minConnectionLength"]=draw_minConnectionLength;
        parameterNameMap["draw_pace"]=draw_pace;
        parameterNameMap["draw_divergence"]=draw_divergence;
        parameterNameMap["draw_destroy"]=draw_destroy;
        parameterNameMap["draw_destroyMode"]=draw_destroyMode;
        parameterNameMap["draw_recInterval"]=draw_recInterval;
        parameterNameMap["draw_currentDrawing"]=draw_currentDrawing;
        parameterNameMap["draw_random"]=draw_random;
        parameterNameMap["draw_randomRate"]=draw_randomRate;
        parameterNameMap["draw_lines"]=draw_lines;
        parameterNameMap["draw_points"]=draw_points;
        parameterNameMap["draw_fresk"]=draw_fresk;
        parameterNameMap["draw_ox"]=draw_ox;
        parameterNameMap["draw_oy"]=draw_oy;
        parameterNameMap["draw_oz"]=draw_oz;
        parameterNameMap["draw_zSpeed"]=draw_zSpeed;
        parameterNameMap["draw_rotY"]=draw_rotY;
        parameterNameMap["draw_freskSpeed"]=draw_freskSpeed;
        parameterNameMap["draw_consecutive"]=draw_consecutive;
        parameterNameMap["draw_simplify"]=draw_simplify;
        parameterNameMap["fractalMode"]=fractalMode;
        parameterNameMap["draw_destruction"]=draw_destruction;
        parameterNameMap["fractalP1"]=fractalP1;
        parameterNameMap["fractalP2"]=fractalP2;
        parameterNameMap["fractalScale"]=fractalScale;
        parameterNameMap["fractalIterations"]=fractalIterations;
        parameterNameMap["glitch_mode "]=glitch_mode ;
        parameterNameMap["glitch_thresh "]=glitch_thresh ;
        parameterNameMap["map_event"]=map_event;
        parameterNameMap["map_remanence"]=map_remanence;
        parameterNameMap["map_mode"]=map_mode;
        parameterNameMap["map_sync"]=map_sync;
        parameterNameMap["map_pace"]=map_pace;
        parameterNameMap["map_prog"]=map_prog;
        parameterNameMap["skewAmpMidi"]=skewAmpMidi;
        parameterNameMap["skewVAmpMidi"]=skewVAmpMidi;
        parameterNameMap["audioGain"]=audioGain;
        parameterNameMap["evolution"]=evolution;
        parameterNameMap["kinect"]=kinect;
        parameterNameMap["kinectRender"]=kinectRender;
        parameterNameMap["MIDIMappingAutoLoad"]=MIDIMappingAutoLoad;
        parameterNameMap["echoPeriod"]=echoPeriod;
        parameterNameMap["echoRandom"]=echoRandom;
        parameterNameMap["echoNb"]=echoNb;
        parameterNameMap["drawBrightDist"]=drawBrightDist;
        parameterNameMap["borderMask"]=borderMask;
        parameterNameMap["ledMode"]=ledMode;
        parameterNameMap["ledSync"]=ledSync;
        parameterNameMap["ledPeriod"]=ledPeriod;
        parameterNameMap["ledInfo"]=ledInfo;
        parameterNameMap["ledBrightness"]=ledBrightness;
        parameterNameMap["ledEvent"]=ledEvent;
        parameterNameMap["ledTint"]=ledTint;
        parameterNameMap["echoAdjust"] = echoAdjust;
        parameterNameMap["omg3D2Scale"] = omg3D2Scale;
        parameterNameMap["omg3D2Strobe"] = omg3D2Strobe;
        parameterNameMap["chromaSepMode"] = chromaSepMode;
        parameterNameMap["user1"] = user1;
        parameterNameMap["user2"] = user2;
        parameterNameMap["user3"] = user3;
        parameterNameMap["user4"] = user4;
        parameterNameMap["user5"] = user5;
        parameterNameMap["omg3D2Depth"] = omg3D2Depth;
        parameterNameMap["pert"] = pert;
        parameterNameMap["pertEvo"] = pertEvo;
        parameterNameMap["pertPersistance"] = pertPersistance;
        parameterNameMap["pertFreq"] = pertFreq;
        parameterNameMap["glitchFreq"] = glitchFreq;

        parameterIDMap.resize(N_PARAM);
        for(map<string,int>::iterator it=parameterNameMap.begin();it!=parameterNameMap.end();it++)
            parameterIDMap[it->second] = it->first;
    }
    
    bool blackNWhiteMedia = false; //indicates wether the media is black n white
    
    bool safeMode = false;
    
    ofxMidiOut midiOut;
    ofxMidiOut midiOutToLive;
    int programChangeFlag = 0;
    int lastProgram = 0;
    float currentParamIntensity = 1;
    
    float xOffset = 0, yOffset=0, xOffsetDelta = 0, yOffsetDelta =0;
    float trapeze = 0.;
    
    std::string controlFile = "";

    bool controlFeedbackOverOmg3D2 = true;
    
    float FINALWIDTH = WIDTH;
    float FINALHEIGHT = HEIGHT;
    bool MULTIPROJECTOR = false;
    bool liveMode = false;
    bool dualDisplay = false;
    
    bool pause = false;

    float parameterMap[N_PARAM]; //1 usec d'appel en map
    float deltaMap[N_PARAM];
    float parameterEasingMap[N_PARAM];
     std::map<string, int> parameterNameMap;
     std::vector<string> parameterIDMap;
    
    ofImage i, grayi, audioImg;
    
    ofxIlda::Frame ildaFrame;   // stores and manages ILDA frame drawings
    
    int lastGlitchDate = 0;
    bool doGlitches = false;
    
    float extAutoDimmer = 1;
};

#endif
