/*
Copyright 2017 Google Inc. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS-IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#ifndef VR_SEURAT_ARTIFACT_COMPRESS_ATLAS_TRANSFORM_H_
#define VR_SEURAT_ARTIFACT_COMPRESS_ATLAS_TRANSFORM_H_

#include <functional>
#include <memory>

#include "seurat/artifact/artifact.h"
#include "seurat/artifact/artifact_processor.h"
#include "seurat/base/status.h"
#include "seurat/image/codec.h"

namespace seurat {
namespace artifact {

// Compresses an Artifact's texture atlas.
//
// Replaces Artifact.component with a MeshComponent.
// Replaces Artifact.texture with a round-trip through the Codec.
// All other properties are unmodified.
class CompressAtlasTransform : public ArtifactProcessor {
 public:
  explicit CompressAtlasTransform(std::unique_ptr<image::Codec> codec)
      : codec_(std::move(codec)) {}

  // ArtifactProcessor implementation
  base::Status Process(Artifact* artifact) const override;

 private:
  // Defines the compression operation for Transform.
  std::unique_ptr<image::Codec> codec_;
};

}  // namespace artifact
}  // namespace seurat

#endif  // VR_SEURAT_ARTIFACT_COMPRESS_ATLAS_TRANSFORM_H_
