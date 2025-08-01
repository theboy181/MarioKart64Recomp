#include "patches.h"

#if 1
/**
 * @brief Renders the item box actor.
 *
 * @param camera
 * @param item_box
 */
RECOMP_PATCH void render_actor_item_box(Camera* camera, struct ItemBox* item_box) {
    UNUSED s32 pad[2];
    Vec3f someVec1;
    Vec3f someVec2;
    Vec3s someRot;
    f32 thing;
    UNUSED s32 pad2;
    Mat4 someMatrix1;
    Mat4 someMatrix2;
    UNUSED s32 pad3[4];
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f12;
    f32 temp_f2;
    f32 temp_f2_2;
    f32 someMultiplier;

    // @recomp Tag the transform.
    gEXMatrixGroupDecomposed(gDisplayListHead++, TAG_ITEM_ADDR(item_box), G_EX_PUSH, G_MTX_MODELVIEW,
                             G_EX_COMPONENT_AUTO, G_EX_COMPONENT_AUTO, G_EX_COMPONENT_AUTO, G_EX_COMPONENT_INTERPOLATE,
                             G_EX_COMPONENT_INTERPOLATE, G_EX_COMPONENT_SKIP, G_EX_COMPONENT_INTERPOLATE,
                             G_EX_ORDER_AUTO, G_EX_EDIT_ALLOW);

    temp_f0 = is_within_render_distance(camera->pos, item_box->pos, camera->rot[1], 0.0f, gCameraZoom[camera - camera1],
                                        4000000.0f);
    if (!(temp_f0 < 0.0f) && !(600000.0f < temp_f0)) {
        if ((item_box->state == 2) && (temp_f0 < 100000.0f)) {
            someRot[0] = 0;
            someRot[1] = item_box->rot[1];
            someRot[2] = 0;
            someVec2[0] = item_box->pos[0];
            someVec2[1] = item_box->resetDistance + 2.0f;
            someVec2[2] = item_box->pos[2];
            mtxf_pos_rotation_xyz(someMatrix1, someVec2, someRot);

            if (!render_set_position(someMatrix1, 0)) {
                return;
            }

            gSPDisplayList(gDisplayListHead++, (u8*) 0x0D002EE8);

            someRot[1] = item_box->rot[1] * 2;
            someVec2[1] = item_box->pos[1];
            mtxf_pos_rotation_xyz(someMatrix1, someVec2, someRot);

            if (!render_set_position(someMatrix1, 0)) {
                return;
            }

            // Normal state
            gDPSetTextureLUT(gDisplayListHead++, G_TT_NONE);
            gSPDisplayList(gDisplayListHead++, (u8*) 0x0d003008);
            gDPSetTextureLUT(gDisplayListHead++, G_TT_RGBA16);
        }
        if (item_box->state == 5) {
            mtxf_pos_rotation_xyz(someMatrix1, item_box->pos, item_box->rot);

            if (!render_set_position(someMatrix1, 0)) {
                return;
            }
            gDPSetTextureLUT(gDisplayListHead++, G_TT_NONE);
            gSPDisplayList(gDisplayListHead++, (u8*) 0x0d003008);
            gDPSetTextureLUT(gDisplayListHead++, G_TT_RGBA16);
        }
        if (item_box->state != 3) {
            mtxf_pos_rotation_xyz(someMatrix1, item_box->pos, item_box->rot);

            if (!render_set_position(someMatrix1, 0)) {
                return;
            }

            gSPClearGeometryMode(gDisplayListHead++, G_LIGHTING);
            gDPSetCombineMode(gDisplayListHead++, G_CC_MODULATEIA, G_CC_MODULATEIA);
            // if ((item_box->rot[1] < 0xAA1) && (item_box->rot[1] > 0)) {
            //     gDPSetRenderMode(gDisplayListHead++, G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2);
            // } else if ((item_box->rot[1] >= 0x6AA5) && (item_box->rot[1] < 0x754E)) {
            //     gDPSetRenderMode(gDisplayListHead++, G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2);
            // } else if ((item_box->rot[1] >= 0x38E1) && (item_box->rot[1] < 0x438A)) {
            //     gDPSetRenderMode(gDisplayListHead++, G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2);
            // } else if ((item_box->rot[1] >= -14575) && (item_box->rot[1] < -11878)) {
            //     gDPSetRenderMode(gDisplayListHead++, G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2);
            // } else {
            gDPSetBlendMask(gDisplayListHead++, 0xFF);
            gDPSetRenderMode(gDisplayListHead++, G_RM_ZB_CLD_SURF, G_RM_ZB_CLD_SURF2);
            // }
            gSPSetGeometryMode(gDisplayListHead++, G_SHADING_SMOOTH);
            gSPDisplayList(gDisplayListHead++, (u8*) 0x0D003090);
        } else {
            gSPClearGeometryMode(gDisplayListHead++, G_LIGHTING);
            gSPClearGeometryMode(gDisplayListHead++, G_CULL_BACK);
            gDPSetBlendMask(gDisplayListHead++, 0xFF);
            thing = item_box->someTimer;
            mtxf_pos_rotation_xyz(someMatrix1, item_box->pos, item_box->rot);
            if (thing < 10.0f) {
                someMultiplier = 1.0f;
            } else {
                someMultiplier = 1.0f - ((thing - 10.0f) * 0.1f);
            }
            mtxf_scale(someMatrix1, someMultiplier);
            if (item_box->someTimer & 1) {
                gDPSetRenderMode(gDisplayListHead++, G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2);
            } else {
                gDPSetRenderMode(gDisplayListHead++, G_RM_AA_ZB_XLU_INTER, G_RM_NOOP2);
            }
            temp_f2 = 2.0f * thing;
            someVec1[0] = 0.0f;
            someVec1[1] = temp_f2;
            someVec1[2] = thing;
            add_translate_mat4_vec3f(someMatrix1, someMatrix2, someVec1);

            if (!render_set_position(someMatrix2, 0)) {
                return;
            }

            gSPDisplayList(gDisplayListHead++, (u8*) 0x0D003158);
            temp_f2_2 = 0.8f * thing;
            temp_f12 = 0.5f * thing;
            someVec1[0] = temp_f2_2;
            someVec1[1] = 2.3f * thing;
            someVec1[2] = temp_f12;
            add_translate_mat4_vec3f(someMatrix1, someMatrix2, someVec1);

            if (!render_set_position(someMatrix2, 0)) {
                return;
            }

            gSPDisplayList(gDisplayListHead++, (u8*) 0x0D0031B8);
            temp_f0_2 = -0.5f * thing;
            someVec1[0] = temp_f2_2;
            someVec1[1] = 1.2f * thing;
            someVec1[2] = temp_f0_2;
            add_translate_mat4_vec3f(someMatrix1, someMatrix2, someVec1);

            if (!render_set_position(someMatrix2, 0)) {
                return;
            }

            gSPDisplayList(gDisplayListHead++, (u8*) 0x0D003128);
            if (!(item_box->someTimer & 1)) {
                gDPSetRenderMode(gDisplayListHead++, G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2);
            } else {
                gDPSetRenderMode(gDisplayListHead++, G_RM_AA_ZB_XLU_INTER, G_RM_NOOP2);
            }
            someVec1[0] = 0.0f;
            someVec1[1] = 1.8f * thing;
            someVec1[2] = -1.0f * thing;
            add_translate_mat4_vec3f(someMatrix1, someMatrix2, someVec1);

            if (!render_set_position(someMatrix2, 0)) {
                return;
            }

            gSPDisplayList(gDisplayListHead++, (u8*) 0x0D0031E8);
            temp_f0_3 = -0.8f * thing;
            someVec1[0] = temp_f0_3;
            someVec1[1] = 0.6f * thing;
            someVec1[2] = temp_f0_2;
            add_translate_mat4_vec3f(someMatrix1, someMatrix2, someVec1);

            if (!render_set_position(someMatrix2, 0)) {
                return;
            }

            gSPDisplayList(gDisplayListHead++, (u8*) 0x0D003188);
            someVec1[0] = temp_f0_3;
            someVec1[1] = temp_f2;
            someVec1[2] = temp_f12;
            add_translate_mat4_vec3f(someMatrix1, someMatrix2, someVec1);

            if (!render_set_position(someMatrix2, 0)) {
                return;
            }

            gSPDisplayList(gDisplayListHead++, (u8*) 0x0D0030F8);
            gSPSetGeometryMode(gDisplayListHead++, G_CULL_BACK);
        }
        gSPTexture(gDisplayListHead++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);
    }
    // @recomp Pop the transform id.
    gEXPopMatrixGroup(gDisplayListHead++, G_MTX_MODELVIEW);
}
#endif

#if 1
/**
 * @brief Renders the fake item box actor.
 *
 * @param camera
 * @param fakeItemBox
 */
RECOMP_PATCH void render_actor_fake_item_box(Camera* camera, struct FakeItemBox* fakeItemBox) {
    Vec3s someRot;
    UNUSED s32 pad[3];
    Vec3f someVec;
    Mat4 someMatrix2;
    Mat4 someMatrix3;
    UNUSED s32 pad2[12];
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f12;
    f32 temp_f2;
    f32 thing;
    f32 temp_f2_2;
    f32 someMultiplier;

    gEXMatrixGroupDecomposed(gDisplayListHead++, TAG_ITEM_ADDR(fakeItemBox), G_EX_PUSH, G_MTX_MODELVIEW,
                             G_EX_COMPONENT_AUTO, G_EX_COMPONENT_AUTO, G_EX_COMPONENT_AUTO, G_EX_COMPONENT_INTERPOLATE,
                             G_EX_COMPONENT_INTERPOLATE, G_EX_COMPONENT_SKIP, G_EX_COMPONENT_INTERPOLATE,
                             G_EX_ORDER_AUTO, G_EX_EDIT_ALLOW);

    if (is_within_render_distance(camera->pos, fakeItemBox->pos, camera->rot[1], 2500.0f, gCameraZoom[camera - camera1],
                                  1000000.0f) < 0) {
        actor_not_rendered(camera, (struct Actor*) fakeItemBox);
        return;
    }
    if (((f32) gCourseMaxY + 800.0f) < fakeItemBox->pos[1]) {
        actor_not_rendered(camera, (struct Actor*) fakeItemBox);
        return;
    }
    if (fakeItemBox->pos[1] < ((f32) gCourseMinY - 800.0f)) {
        actor_not_rendered(camera, (struct Actor*) fakeItemBox);
        return;
    }

    actor_rendered(camera, (struct Actor*) fakeItemBox);
    someRot[0] = 0;
    someRot[1] = fakeItemBox->rot[1];
    someRot[2] = 0;
    mtxf_pos_rotation_xyz(someMatrix2, fakeItemBox->pos, someRot);
    mtxf_scale(someMatrix2, fakeItemBox->sizeScaling);

    if (fakeItemBox->state != 2) {
        if (!render_set_position(someMatrix2, 0)) {
            return;
        }
        gDPSetTextureLUT(gDisplayListHead++, G_TT_NONE);
        gSPDisplayList(gDisplayListHead++, (Gfx*) 0xd002f80);
        gDPSetTextureLUT(gDisplayListHead++, G_TT_RGBA16);
        mtxf_pos_rotation_xyz(someMatrix2, fakeItemBox->pos, fakeItemBox->rot);
        mtxf_scale(someMatrix2, fakeItemBox->sizeScaling);

        if (!render_set_position(someMatrix2, 0)) {
            return;
        }

        gSPClearGeometryMode(gDisplayListHead++, G_LIGHTING);
        gDPSetCombineMode(gDisplayListHead++, G_CC_MODULATEIA, G_CC_MODULATEIA);
        // if ((fakeItemBox->rot[1] < 0xAA1) && (fakeItemBox->rot[1] > 0)) {
        //     gDPSetRenderMode(gDisplayListHead++, G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2);
        // } else if ((fakeItemBox->rot[1] >= 0x6AA5) && (fakeItemBox->rot[1] < 0x754E)) {
        //     gDPSetRenderMode(gDisplayListHead++, G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2);
        // } else if ((fakeItemBox->rot[1] >= 0x38E1) && (fakeItemBox->rot[1] < 0x438A)) {
        //     gDPSetRenderMode(gDisplayListHead++, G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2);
        // } else if ((fakeItemBox->rot[1] >= 0xC711) && (fakeItemBox->rot[1] < 0xD1BA)) {
        //     gDPSetRenderMode(gDisplayListHead++, G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2);
        // } else {
        gDPSetBlendMask(gDisplayListHead++, 0xFF);
        gDPSetRenderMode(gDisplayListHead++, G_RM_ZB_CLD_SURF, G_RM_ZB_CLD_SURF2);
        // }
        gSPDisplayList(gDisplayListHead++, (Gfx*) 0x0D003090);
    } else {
        gSPClearGeometryMode(gDisplayListHead++, G_LIGHTING);
        gSPClearGeometryMode(gDisplayListHead++, G_CULL_BACK);
        gDPSetBlendMask(gDisplayListHead++, 0xFF);
        thing = fakeItemBox->someTimer;
        mtxf_pos_rotation_xyz(someMatrix2, fakeItemBox->pos, fakeItemBox->rot);
        if (thing < 10.0f) {
            someMultiplier = 1.0f;
        } else {
            someMultiplier = 1.0f - ((thing - 10.0f) * 0.1f);
        }
        mtxf_scale(someMatrix2, someMultiplier);
        if (fakeItemBox->someTimer & 1) {
            gDPSetRenderMode(gDisplayListHead++, G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2);
        } else {
            gDPSetRenderMode(gDisplayListHead++, G_RM_AA_ZB_XLU_INTER, G_RM_NOOP2);
        }
        temp_f2 = 2.0f * thing;
        someVec[0] = 0.0f;
        someVec[1] = temp_f2;
        someVec[2] = thing;
        add_translate_mat4_vec3f(someMatrix2, someMatrix3, someVec);

        if (!render_set_position(someMatrix3, 0)) {
            return;
        }

        gSPDisplayList(gDisplayListHead++, (Gfx*) 0x0D003158);
        temp_f2_2 = 0.8f * thing;
        temp_f12 = 0.5f * thing;
        someVec[0] = temp_f2_2;
        someVec[1] = 2.3f * thing;
        someVec[2] = temp_f12;
        add_translate_mat4_vec3f(someMatrix2, someMatrix3, someVec);

        if (!render_set_position(someMatrix3, 0)) {
            return;
        }

        gSPDisplayList(gDisplayListHead++, (Gfx*) 0x0D0031B8);
        temp_f0_2 = -0.5f * thing;
        someVec[0] = temp_f2_2;
        someVec[1] = 1.2f * thing;
        someVec[2] = temp_f0_2;
        add_translate_mat4_vec3f(someMatrix2, someMatrix3, someVec);

        if (!render_set_position(someMatrix3, 0)) {
            return;
        }

        gSPDisplayList(gDisplayListHead++, (Gfx*) 0x0D003128);
        if (!(fakeItemBox->someTimer & 1)) {
            gDPSetRenderMode(gDisplayListHead++, G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2);
        } else {
            gDPSetRenderMode(gDisplayListHead++, G_RM_AA_ZB_XLU_INTER, G_RM_NOOP2);
        }
        someVec[0] = 0.0f;
        someVec[1] = 1.8f * thing;
        someVec[2] = -1.0f * thing;
        add_translate_mat4_vec3f(someMatrix2, someMatrix3, someVec);

        if (!render_set_position(someMatrix3, 0)) {
            return;
        }

        gSPDisplayList(gDisplayListHead++, (Gfx*) 0x0D0031E8);
        temp_f0_3 = -0.8f * thing;
        someVec[0] = temp_f0_3;
        someVec[1] = 0.6f * thing;
        someVec[2] = temp_f0_2;
        add_translate_mat4_vec3f(someMatrix2, someMatrix3, someVec);

        if (!render_set_position(someMatrix3, 0)) {
            return;
        }

        gSPDisplayList(gDisplayListHead++, (Gfx*) 0x0D003188);
        someVec[0] = temp_f0_3;
        someVec[1] = temp_f2;
        someVec[2] = temp_f12;
        add_translate_mat4_vec3f(someMatrix2, someMatrix3, someVec);

        if (!render_set_position(someMatrix3, 0)) {
            return;
        }

        gSPDisplayList(gDisplayListHead++, (Gfx*) 0x0D0030F8);
        gSPSetGeometryMode(gDisplayListHead++, G_CULL_BACK);
    }
    // @recomp Pop the transform id.
    gEXPopMatrixGroup(gDisplayListHead++, G_MTX_MODELVIEW);
}
#endif

#if 0
RECOMP_PATCH void func_80068DA0(Player* player, UNUSED s8 arg1, UNUSED f32 arg2, s8 arg3, s8 arg4) {
    Vec3f sp9C;
    Vec3s sp94;

    if ((player->unk_258[20 + arg4].unk_01C == 1) && ((s32) player->animFrameSelector[arg3] < 0xD)) {
        sp9C[1] = (player->pos[1] - 3.0f) + player->unk_258[20 + arg4].unk_000[1];
        sp9C[2] = player->pos[2] + (coss(player->unk_048[arg3]) * -10.0f);
        sp9C[0] = player->pos[0] + (sins(player->unk_048[arg3]) * -10.0f);
        sp94[0] = 0;
        sp94[1] = player->unk_048[arg3];
        sp94[2] = 0;
        func_800652D4(sp9C, sp94, player->unk_258[20 + arg4].unk_00C * player->size);
        gSPDisplayList(gDisplayListHead++, (Gfx*)0x0D008C90);
        gDPLoadTLUT_pal256(gDisplayListHead++, (Gfx*)0x800E52D0);
        gDPSetTextureLUT(gDisplayListHead++, G_TT_RGBA16);
        gDPLoadTextureBlock(gDisplayListHead++, (Gfx*)0x8018D4A4, G_IM_FMT_CI, G_IM_SIZ_8b, 64, 32, 0,
                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                            G_TX_NOLOD);
        gSPVertex(gDisplayListHead++, (Gfx*)0x800E8B80, 4, 0);
        gSPDisplayList(gDisplayListHead++, (Gfx*)0xd008c78);
        gDPLoadTextureBlock(gDisplayListHead++, (Gfx*)0x8018D4A8, G_IM_FMT_CI, G_IM_SIZ_8b, 64, 32, 0,
                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                            G_TX_NOLOD);
        gSPVertex(gDisplayListHead++, (Gfx*)0x800E8BC0, 4, 0);
        gSPDisplayList(gDisplayListHead++, (Gfx*)0x0D008DA0);
        gDPSetTextureLUT(gDisplayListHead++, G_TT_NONE);
        gMatrixEffectCount += 1;
    }
}
#endif

#if 0
RECOMP_PATCH void func_80067964(Player* player, UNUSED s8 arg1, f32 arg2, UNUSED s8 arg3, s8 arg4) {
    Vec3f sp9C;
    Vec3s sp94;

    if (player->unk_258[20 + arg4].unk_01C == 1) {
        sp9C[0] = player->unk_258[20 + arg4].unk_000[0];
        sp9C[1] = player->unk_258[20 + arg4].unk_000[1];
        sp9C[2] = player->unk_258[20 + arg4].unk_000[2];
        sp94[0] = 0;
        sp94[1] = player->unk_258[20 + arg4].unk_020;
        sp94[2] = 0;
        func_800652D4(sp9C, sp94, player->size * arg2);
        gSPDisplayList(gDisplayListHead++, (Gfx*)0x0D008C90);
        gSPClearGeometryMode(gDisplayListHead++, G_CULL_BOTH);
        gDPLoadTLUT_pal256(gDisplayListHead++, (Gfx*)0x800E52D0);
        gDPSetTextureLUT(gDisplayListHead++, G_TT_RGBA16);
        gDPLoadTextureBlock(gDisplayListHead++, (Gfx*)0x8018D4AC, G_IM_FMT_CI, G_IM_SIZ_8b, 64, 32, 0,
                            G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                            G_TX_NOLOD, G_TX_NOLOD);
        gSPVertex(gDisplayListHead++, (Gfx*)0x800E8840, 4, 0);
        gSPDisplayList(gDisplayListHead++, (Gfx*)0xd008c78);
        gDPLoadTextureBlock(gDisplayListHead++, (Gfx*)0x8018D4B0, G_IM_FMT_CI, G_IM_SIZ_8b, 64, 32, 0,
                            G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                            G_TX_NOLOD, G_TX_NOLOD);
        gSPVertex(gDisplayListHead++, (Gfx*)0x800E8800, 4, 0);
        gSPDisplayList(gDisplayListHead++, (Gfx*)0x0D008DA0);
        gDPSetTextureLUT(gDisplayListHead++, G_TT_NONE);
        gMatrixEffectCount += 1;
    }
}
#endif

#if 0
RECOMP_PATCH void func_80068310(Player* player, UNUSED s8 arg1, UNUSED f32 arg2, s8 arg3, s8 arg4) {
    UNUSED s32 stackPadding[16]; // huh?
    Vec3f sp9C;
    Vec3s sp94;

    if (player->unk_258[20 + arg4].unk_01C == 1) {
        sp9C[1] = player->unk_258[20 + arg4].unk_000[1];
        sp9C[2] = player->pos[2] + (coss(player->unk_048[arg3]) * -10.0f);
        sp9C[0] = player->pos[0] + (sins(player->unk_048[arg3]) * -10.0f);
        sp94[0] = 0;
        sp94[1] = player->unk_048[arg3];
        sp94[2] = 0;
        func_800652D4(sp9C, sp94, player->unk_258[20 + arg4].unk_00C * player->size);
        gSPDisplayList(gDisplayListHead++, (Gfx*)0x0D008C90);
        gDPLoadTLUT_pal256(gDisplayListHead++, (Gfx*)0x800E52D0);
        gDPSetTextureLUT(gDisplayListHead++, G_TT_RGBA16);
        gDPLoadTextureBlock(gDisplayListHead++, (Gfx*)0x8018D4B4, G_IM_FMT_CI, G_IM_SIZ_8b, 64, 32, 0,
                            G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                            G_TX_NOLOD, G_TX_NOLOD);
        gSPVertex(gDisplayListHead++, (Gfx*)0x800E8880, 4, 0);
        gSPDisplayList(gDisplayListHead++, (Gfx*)0xd008c78);
        gDPLoadTextureBlock(gDisplayListHead++, (Gfx*)0x8018D4B8, G_IM_FMT_CI, G_IM_SIZ_8b, 64, 32, 0,
                            G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                            G_TX_NOLOD, G_TX_NOLOD);
        gSPVertex(gDisplayListHead++, (Gfx*)0x800E88C0, 4, 0);
        gSPDisplayList(gDisplayListHead++, (Gfx*)0x0D008DA0);
        gDPSetTextureLUT(gDisplayListHead++, G_TT_NONE);
        gMatrixEffectCount += 1;
    }
}
#endif